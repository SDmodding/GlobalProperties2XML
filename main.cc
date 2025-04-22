#define THEORY_IMPL
#define THEORY_TRIADWARS
#define THEORY_DUCKTAPE
#define THEORY_QSYMBOL_TABLE_INVENTORY
#include "theory/theory.hh"

#include "console.hh"
#include "propertyset2xml.hh"

using namespace UFG;

//--------------------------------------------
//	Entrypoint
//--------------------------------------------

int main(int argc, char** argv)
{
	qInit();

	qConsole con(argc, argv);

	auto gamePath = con.GetArgument("-gamepath");
	auto qsymbolsDictionary = con.GetArgument("-qsymbols");
	auto outPath = con.GetArgument("-out");

	if (gamePath.IsEmpty())
	{
		qPrintf("ERROR: '-gamepath' is not set!\n");
		return 1;
	}

	if (!gamePath.EndsWith("\\")) {
		gamePath += "\\";
	}

	if (!qsymbolsDictionary.IsEmpty() && StreamResourceLoader::LoadResourceFile(qsymbolsDictionary)) {
		gSymbolMap.Build();
	}
	else {
		qPrintf("WARN: No qSymbols dictionary loaded - path not set or failed to load.\n");
	}

	if (!outPath.IsEmpty() && !outPath.EndsWith("\\")) {
		outPath += "\\";
	}

	BigFileSystem::m_BigFileNamePrefix = gamePath;
	if (!StreamResourceLoader::LoadResourceFile(BigFileSystem::BigFilePrepend("Global.bix")))
	{
		qPrintf("ERROR: Failed to load 'Global.bix', make sure the '-gamepath' contains the file.\n");
		return 1;
	}

	// Triad Wars
	{
		auto global1 = BigFileSystem::BigFilePrepend("Global1.bix");
		if (qFileExists(global1)) {
			StreamResourceLoader::LoadResourceFile(global1);
		}
	}

	const char* globalProperties = R"(Data\Global\PropertySets\GlobalProperties.bin)";
	if (!StreamResourceLoader::LoadResourceFile(globalProperties))
	{
		qPrintf("ERROR: Failed to load '%s'.\n", globalProperties);
		return 1;
	}

	if (auto inventory = qResourceWarehouse::Instance()->GetInventory(RTypeUID_qPropertySetResource))
	{
		for (auto data : inventory->mResourceDatas)
		{
			auto propertySetResource = static_cast<qPropertySetResource*>(data);
			auto name = propertySetResource->GetNameString();

			if (!name)
			{
				qPrintf("WARN: Skipping '0x%08X' because it has no name.\n", data->mNode.mUID);
				continue;
			}

			qPrintf("INFO: Exporting %s\n", name);

			qString filename = outPath;
			filename += propertySetResource->GetNameString();
			filename += ".xml";

			qPropertySet2XML propertySet2XML = { propertySetResource };
			propertySet2XML.Export(filename);
		}
	}

	abort();
	return 0;
}