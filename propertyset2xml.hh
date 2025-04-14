#pragma once
#include "propertyset_schemas.hh"

using namespace UFG;

class qSymbolMap
{
public:
	std::map<u32, const char*> mMap;
	std::map<u32, const char*> mUppercaseMap;
	std::map<u32, const char*> mWWiseMap;

	void Build()
	{
		auto inventory = SymbolTableResourceInventory::Get();
		for (auto resource_data : inventory->mResourceDatas)
		{
			auto symbolResource = static_cast<SymbolTableResource*>(resource_data);
			auto entry = symbolResource->mEntries.Get();

			for (u32 i = 0; symbolResource->mNumEntries > i; ++i)
			{
				auto str = entry->mString.Get();

				mMap[qSymbol::create_from_string(str)] = str;
				mUppercaseMap[qSymbolUC::create_from_string(str)] = str;
				mWWiseMap[qWiseSymbol::create_from_string(str)] = str;

				++entry;
			}
		}
	}

	const char* Find(u32 uid, int type)
	{
		if (1 >= type)
		{
			if (auto str = qSymbolLookupStringFromSymbolTableResources(uid)) {
				return str;
			}
		}

		std::map<u32, const char*>* map;

		switch (type)
		{
		default:
			map = &mMap; break;
		case 1:
			map = &mUppercaseMap; break;
		case 2:
			map = &mWWiseMap; break;
		}

		auto it = map->find(uid);
		if (it != map->end()) {
			return (*it).second;
		}


		if (1 >= type)
		{
			if (auto propResource = PropertySetCache::GetResource(uid)) {
				return propResource->GetNameString();
			}
		}

		return 0;
	}
	
} inline gSymbolMap;

class qPropertySet2XML
{
public:
	qPropertySetResource* mResource;
	SimpleXML::XMLWriter* mXMLW;

	std::map<u32, int> mUnresolvedSymbols;

	qPropertySet2XML(qPropertySetResource* resource) : mResource(resource)
	{
		mXMLW = SimpleXML::XMLWriter::CreateBuffer(0x8000, 0);
	}

	~qPropertySet2XML()
	{
		qString filename = mResource->GetNameString();
		filename += ".xml";

		mXMLW->CloseBufferAndWriteToFile(filename);
		mXMLW = 0;
	}

	// Symbols

	qString FormatUID(u32 uid) { return { "0x%X", uid }; }
	qString FormatSymbol(u32 uid)
	{
		static int sIndex;
		static char sBuffer[16 * 8];

		char* pBuffer = &sBuffer[16 * (sIndex++ % 8)];
		qSPrintf(pBuffer, "~%08x~", uid);
		return pBuffer;
	}

	const char* FindSymbol(u32 uid, int type, bool required)
	{
		if (auto str = gSymbolMap.Find(uid, type)) {
			return str;
		}

		mUnresolvedSymbols[uid] = type;

		if (!required) {
			return 0;
		}

		return FormatSymbol(uid);
	}

	const char* qSymbolStr(u32 uid, bool required = 1) { return FindSymbol(uid, 0, required); }
	const char* qSymbolUCStr(u32 uid, bool required = 1) { return FindSymbol(uid, 1, required); }
	const char* qWiseSymbolStr(u32 uid, bool required = 1) { return FindSymbol(uid, 2, required); }

	// Properties

	void ExportProperty2(u32 type, void* mem)
	{
		qString value;

		switch (type)
		{
		case UID_int8:
			value.Format("%d", static_cast<int>(*reinterpret_cast<i8*>(mem))); break;
		case UID_int16:
			value.Format("%d", static_cast<int>(*reinterpret_cast<i16*>(mem))); break;
		case UID_int32:
			value.Format("%d", *reinterpret_cast<i32*>(mem)); break;
		case UID_int64:
			value.Format("%lld", *reinterpret_cast<i64*>(mem)); break;
		case UID_int128:
			qDebugBreak();
			break;
		case UID_uint8:
			value.Format("%u", static_cast<u32>(*reinterpret_cast<u8*>(mem))); break;
			break;
		case UID_uint16:
			value.Format("%u", static_cast<u32>(*reinterpret_cast<u16*>(mem))); break;
			break;
		case UID_uint32:
			value.Format("%u", *reinterpret_cast<u32*>(mem)); break;
			break;
		case UID_uint64:
			value.Format("%llu", *reinterpret_cast<u64*>(mem)); break;
			break;
		case UID_bool:
			value = (*reinterpret_cast<bool*>(mem) ? "true" : "false"); break;
		case UID_float:
			value.Format("%.6g", *reinterpret_cast<f32*>(mem)); break;
			break;
		case UID_double:
			value.Format("%.6g", *reinterpret_cast<f64*>(mem)); break;
			break;
		case UID_string:
		{
			if (auto str = reinterpret_cast<qOffset64<const char*>*>(mem)->Get()) {
				value = str;
			}
		}
		break;
		case UID_rangedFloat:
			qDebugBreak();
			break;
		case UID_rangedUint32:
			qDebugBreak();
			break;
		case UID_rangedInt32:
		{
			auto range = reinterpret_cast<int*>(mem);

			value.Format("%d", range[1]); mXMLW->AddAttribute("range", value);
			value.Format("%d", range[0]);
		}
		break;
		case UID_weightedList:
			qDebugBreak();
			break;
		case UID_qVector2:
		{
			auto vec = reinterpret_cast<qVector2*>(mem);
			qString v;
			v.Format("%.6g", vec->x); mXMLW->AddAttribute("x", v);
			v.Format("%.6g", vec->y); mXMLW->AddAttribute("y", v);
		}
		break;
		case UID_qVector3:
		{
			auto vec = reinterpret_cast<qVector3*>(mem);
			qString v;
			v.Format("%.6g", vec->x); mXMLW->AddAttribute("x", v);
			v.Format("%.6g", vec->y); mXMLW->AddAttribute("y", v);
			v.Format("%.6g", vec->z); mXMLW->AddAttribute("z", v);
		}
		break;
		case UID_qVector4:
		{
			auto vec = reinterpret_cast<qVector4*>(mem);
			qString v;
			v.Format("%.6g", vec->x); mXMLW->AddAttribute("x", v);
			v.Format("%.6g", vec->y); mXMLW->AddAttribute("y", v);
			v.Format("%.6g", vec->z); mXMLW->AddAttribute("z", v);
			v.Format("%.6g", vec->w); mXMLW->AddAttribute("w", v);
		}
		break;
		case UID_qMatrix44:
		case UID_TransRot:
		{
			auto trans = reinterpret_cast<qMatrix44*>(mem);

			mXMLW->BeginNode("Forward");
			ExportProperty2(UID_qVector3, &trans->v0);
			mXMLW->EndNode("Forward");

			mXMLW->BeginNode("Up");
			ExportProperty2(UID_qVector3, &trans->v2);
			mXMLW->EndNode("Up");

			mXMLW->BeginNode("Translation");
			ExportProperty2(UID_qVector3, &trans->v3);
			mXMLW->EndNode("Translation");
		}
		break;
		case UID_qResHandle:
			qDebugBreak();
			break;
		case UID_qSymbol:
		{
			u32 uid = *reinterpret_cast<u32*>(mem);
			if (uid == 0 || uid == -1) {
				break;
			}

			mXMLW->AddAttribute("symUID", FormatUID(uid));
			value = qSymbolStr(uid, 0);
		}
		break;
		case UID_qSymbolUC:
		{
			u32 uid = *reinterpret_cast<u32*>(mem);
			if (uid == 0 || uid == -1) {
				break;
			}

			mXMLW->AddAttribute("symUID", FormatUID(uid));
			value = qSymbolUCStr(uid, 0);
		}
		break;
		case UID_qWiseSymbol:
		{
			u32 uid = *reinterpret_cast<u32*>(mem);
			if (uid == 0 || uid == -1) {
				break;
			}

			mXMLW->AddAttribute("symUID", FormatUID(uid));
			value = qWiseSymbolStr(uid, 0);
		}
		break;
		case UID_list:
		{
			auto propList = reinterpret_cast<qOffset64<qPropertyList*>*>(mem)->Get();
			ExportPropertyList(propList);
		}
		break;
		case UID_propertyset:
		{
			auto propSet = reinterpret_cast<qOffset64<qPropertySet*>*>(mem)->Get();
			ExportPropertySet(propSet);
		}
		break;
			break;
		case UID_qTransQuat:
		{
			auto tq = reinterpret_cast<qTransQuat*>(mem);
			qString v;
			v.Format("%.6g", tq->mTrans.x); mXMLW->AddAttribute("tx", v);
			v.Format("%.6g", tq->mTrans.y); mXMLW->AddAttribute("ty", v);
			v.Format("%.6g", tq->mTrans.z); mXMLW->AddAttribute("tz", v);
			v.Format("%.6g", tq->mRot.x); mXMLW->AddAttribute("rx", v);
			v.Format("%.6g", tq->mRot.y); mXMLW->AddAttribute("ry", v);
			v.Format("%.6g", tq->mRot.z); mXMLW->AddAttribute("rz", v);
			v.Format("%.6g", tq->mRot.w); mXMLW->AddAttribute("rw", v);
		}
		break;
		}

		if (value.IsEmpty()) {
			return;
		}

		qString replaceStr = "\n";
		for (int i = 0; (mXMLW->mData->mIndent - 2) > i; ++i) {
			replaceStr.append("\t", 1);
		}

		if (value.ReplaceString("\n", replaceStr, 1)) {
			bool debug = true;
		}

		mXMLW->AddValue(value);
	}

	void ExportProperty(u32 type_uid, void* mem, const char* name, const char* type_name)
	{
		if (type_uid >= PROPERTY_SET_DATA_TYPE_COUNT) {
			return;
		}

		mXMLW->BeginNode("Property");

		/* Attributes */

		mXMLW->AddAttribute("name", name);
		mXMLW->AddAttribute("type", type_name);

		ExportProperty2(type_uid, mem);

		mXMLW->EndNode("Property");
	}

	void ExportProperty(qProperty* property, void* mem)
	{
		if (property->mTypeUID >= PROPERTY_SET_DATA_TYPE_COUNT) {
			return;
		}

		auto propertyType = qPropertyType::Get(property->mTypeUID);
		ExportProperty(property->mTypeUID, mem, qSymbolStr(property->mNameUID), propertyType->mXMLTag);
	}

	void ExportPropertyList(qPropertyList* property_list)
	{
		if (property_list->mTypeUID >= PROPERTY_SET_DATA_TYPE_COUNT) {
			return;
		}

		if (property_list->mNumElements <= 0) {
			return;
		}

		mXMLW->AddComment(" Elements ");

		auto propertyType = qPropertyType::Get(property_list->mTypeUID);

		auto element = property_list->mValues.Get();
		for (u32 i = 0; property_list->mNumElements > i; ++i)
		{
			mXMLW->BeginNode("ListProperty");
			mXMLW->AddAttribute("type", propertyType->mXMLTag);

			ExportProperty2(property_list->mTypeUID, element);

			mXMLW->EndNode("ListProperty");

			element += property_list->mElementSize;
		}
	}

	void ExportPropertySet(qPropertySet* property_set, const char* name = 0, const char* xmlTag = "PropertySet")
	{
		mXMLW->BeginNode(xmlTag);

		const u32 nameUID = property_set->GetName();
		const u32 schemaName = property_set->GetSchemaName();

		/* Attributes */

		if (nameUID != 0 && nameUID != -1)
		{
			if (!name) {
				name = qSymbolStr(nameUID, 0);
			}

			if (name) {
				mXMLW->AddAttribute("name", name);
			}

			mXMLW->AddAttribute("nameUID", FormatUID(nameUID));
		}

		if (property_set->GetFlags(qPropertySet::FLAG_INHERIT_SCHEMA)) {
			mXMLW->AddAttribute("schema", "$inherit");
		}
		else if (auto schemaPropSet = PropertySetCache::GetPropSet(schemaName)) {
			mXMLW->AddAttribute("schema", qSymbolStr(schemaPropSet->GetName()));
		}

		if (property_set->GetFlags(qPropertySet::FLAG_COMPONENT_SCHEMA)) {
			mXMLW->AddAttribute("schematype", "component");
		}

		if (property_set->GetFlags(qPropertySet::FLAG_CS_SKIP_PARENT_CHECK)) {
			mXMLW->AddAttribute("skipparentcheck", "1");
		}

		/* Parents */

		const u32 numParents = property_set->mNumParents;
		if (numParents) {
			mXMLW->AddComment(" Parents ");
		}

		auto parent = property_set->mParents.Get();

		for (u32 i = 0; numParents > i; ++i)
		{
			const char* parentName = 0;
			u32 parentNameUID = -1;

			if (auto parentResource = PropertySetCache::GetResource(parent->mNameUID))
			{
				parentName = parentResource->GetNameString();
				parentNameUID = parentResource->mNode.mUID;
			}
			else if (auto parentPropSet = PropertySetCache::GetPropSet(parent->mNameUID))
			{
				parentNameUID = parentPropSet->GetName();
				parentName = qSymbolStr(parentNameUID);
			}

			if (parentName)
			{
				mXMLW->BeginNode("Parent");
				mXMLW->AddAttribute("nameUID", FormatUID(parentNameUID));
				mXMLW->AddValue(parentName);
				mXMLW->EndNode("Parent");
			}

			++parent;
		}

		/* Properties */

		const u32 numProperties = property_set->mNumProperties;
		if (numProperties) {
			mXMLW->AddComment(" Properties ");
		}

		auto property = property_set->mProperties.Get();
		auto values = property_set->mValues.Get();

		for (u32 i = 0; numProperties > i; ++i)
		{
			ExportProperty(property, &values[property->GetDataOffset()]);
			++property;
		}

		/* Schema Properties */

		// Normally it should be searched by "schemaName", but we only dump information to not have duplicates from parents.
		// Modify it in future if we can somehow load them directly to the game from XML file.

		auto schemaIt = gPropertySetSchemas.find(nameUID);
		if (schemaIt == gPropertySetSchemas.end()) {
			schemaIt = gPropertySetSchemas.find(schemaName);
		}

		if (schemaIt != gPropertySetSchemas.end())
		{
			bool hasSchemaProperties = 0;
			bool isSchemaParent = 0;
			auto ownerSet = mResource->GetPropertySet();

			do
			{
				auto schema = schemaIt->second;
				bool currentComponent = 0;
				if (mXMLW->mData->mIndent > 3) {
					currentComponent = 1;
				}
				else if (auto mem = ownerSet->GetValuePtr(UID_propertyset, schemaIt->first, DEPTH_LOCAL))
				{
					if (auto propSet = reinterpret_cast<qOffset64<qPropertySet*>*>(mem)->Get())
					{
						if (propSet == property_set) {
							currentComponent = 1;
						}
					}
				}

				if (currentComponent)
				{
					for (auto& property : schema.mProperties)
					{
						if (!hasSchemaProperties)
						{
							hasSchemaProperties = 1;
							mXMLW->AddComment(" Schema Properties ");
						}

						auto propertyType = qPropertyType::Get(property.mType);
						ExportProperty(property.mType, &values[property.mOffset], property.mName, propertyType->mXMLTag);
					}
				}
				else if (isSchemaParent)
				{
					qString str = { " Schema Parent: %s ", qSymbolStr(schemaIt->first) };
					mXMLW->AddComment(str);
				}


				isSchemaParent = 1;
				schemaIt = gPropertySetSchemas.find(schema.mParentUID);

			} while (schemaIt != gPropertySetSchemas.end());
		}

		mXMLW->EndNode(xmlTag);
	}

	void Export()
	{
		auto propSet = mResource->GetPropertySet();
		ExportPropertySet(propSet, mResource->GetNameString(), "PropertySetResource");

		if (mUnresolvedSymbols.empty()) {
			return;
		}

		mXMLW->AddComment(" List of unresolved symbols ");

		for (auto& pair : mUnresolvedSymbols)
		{
			const char* type = (pair.second == 2 ? "WWise" : pair.second == 1 ? "Uppercase" : "Normal");
			qString strUID = FormatUID(pair.first);
			qString str = { " %s (%s) ", strUID.mData, type };
			mXMLW->AddComment(str);
		}
	}
};