#pragma once

using namespace UFG;

struct qSchemaProperty
{
	const char* mName;
	u32 mType;
	u32 mOffset;
};

struct qPropertySetSchema
{
	u32 mParentUID;
	std::vector<qSchemaProperty> mProperties;
};

std::map<u32, qPropertySetSchema> gPropertySetSchemas = {
	// schema_classlist
	{ 0x17B9254E, { 0, {
		{ "ClassTypeIsAllowable", UID_bool, 0 },
		{ "ClassTypeList", UID_list, 0x8 }
	}}},
	// schema_doorphantominfo
	{ 0x7DF1FF7A, { 0, { // "default-schema-doorphantominfo"
		{ "door_name", UID_qSymbolUC, 0 },
		{ "extentX", UID_float, 0x4 },
		{ "extentY", UID_float, 0x8 },
		{ "door_height", UID_float, 0xC },
		{ "height_offset", UID_float, 0x10 },
		{ "extend_left", UID_bool, 0x14 },
		{ "extend_forward", UID_bool, 0x15 }
	}}},
	// schema_interactionPoint
	{ 0x886E1502, { 0, { // "InteractionPoint"
		{ "IPActive", UID_bool, 0 },
		{ "IPUpdate", UID_qSymbol, 0x4 },
		{ "IPTarget", UID_qSymbol, 0x8 },
		{ "IPOffsetTarget", UID_qSymbol, 0xC },
		{ "IPDistance", UID_float, 0x10 },
		{ "IPBoneName", UID_qSymbolUC, 0x14 },
		{ "IPXform", UID_qMatrix44, 0x18 },
	}}},
	// schema_interestpoint_script
	{ 0xA0D43F36, { 0, {
		{ "HasBeginningScript", UID_bool, 0 },
		{ "HasEndingScript", UID_bool, 0x1 },
		{ "BeginningScriptText", UID_string, 0x8 },
		{ "EndingScriptText", UID_string, 0x10 },
		{ "BeginningScriptClass", UID_string, 0x18 },
		{ "EndingScriptClass", UID_string, 0x20 },
		{ "HasOnReservationScript", UID_bool, 0x28 },
		{ "OnReservationScriptText", UID_string, 0x30 },
		{ "OnReservationScriptClass", UID_string, 0x38 }
	}}},
	// component_AIActionTree
	{ 0x523487F, { 0, {
		{ "AIBehaviour", UID_string, 0 }
	}}},
	// component_BaseAnimation
	{ 0x5BCDBCDE, { 0, {
		{ "DestroyAttachedCharacters", UID_bool, 0 },
		{ "RigName", UID_string, 0x8 },
		{ "WeightSetFileName", UID_string, 0x10 },
		{ "PoseDriverSet", UID_qSymbolUC, 0x18 },
		{ "RigNameHD", UID_string, 0x20 },
		{ "WeightSetFileNameHD", UID_string, 0x28 },
		{ "PoseDriverSetHD", UID_qSymbolUC, 0x30 },
		{ "RequiredAnimBanks", UID_list, 0x38 },
		{ "pad_BaseAnimation", UID_uint32, 0x40 }
	}}},
	// component_CameraAnimation
	{ 0x7483CC0F, { 0x5BCDBCDE }},
	// component_CharacterAnimation
	{ 0x34DB99FB, { 0x5BCDBCDE }},
	// component_CharacterEffects
	{ 0x95BB3A32, { 0, {
		{ "fxPlayerWalkingThroughWater", UID_qSymbolUC, 0 },
		{ "fxPlayerWalkingThroughWaterMinSpeed", UID_float, 0x4 },
		{ "fxMaxWaterDepthForWalkingThroughWaterEffect", UID_float, 0x8 }
	}}},
	// component_CharacterPhysics
	{ 0xA27BEFF2, { 0, {
		{ "Mass", UID_float, 0 },
		{ "MaxForce", UID_float, 0x4 },
		{ "MaxClimableSlope", UID_float, 0x8 },
		{ "WalkCollisionHeight", UID_float, 0xC },
		{ "CombatCollisionHeight", UID_float, 0x10 },
		{ "CrouchCollisionHeight", UID_float, 0x14 },
		{ "DrivingCollisionHeight", UID_float, 0x18 },
		{ "CrawlCollisionHeight", UID_float, 0x1C },
		{ "SittingCollisionHeight", UID_float, 0x20 },
		{ "CoverCollisionHeight", UID_float, 0x24 },
		{ "FreerunCollisionHeight", UID_float, 0x28 },
		{ "WalkCollisionRadius", UID_float, 0x2C },
		{ "CombatCollisionRadius", UID_float, 0x30 },
		{ "CrouchCollisionRadius", UID_float, 0x34 },
		{ "DrivingCollisionRadius", UID_float, 0x38 },
		{ "CrawlCollisionRadius", UID_float, 0x3C },
		{ "SittingCollisionRadius", UID_float, 0x40 },
		{ "CoverCollisionRadius", UID_float, 0x44 },
		{ "FreerunCollisionRadius", UID_float, 0x48 },
		{ "DetailedOnGroundCheck", UID_bool, 0x4C }
	}}},
	// component_PhysicsMover
	{ 0x14B9F38F, { 0, {
		{ "physicsPropertySetAI", UID_qSymbol, 0 },
		{ "physicsPropertySetHuman", UID_qSymbol, 0x4 },
		{ "modelName", UID_string, 0x8 },
		{ "TrunkType", UID_qSymbol, 0x10 },
		{ "damageMultiplierWorldCollisions", UID_float, 0x14 },
		{ "damageMultiplierVehicleCollisions", UID_float, 0x18 },
		{ "damageMultiplierBullets", UID_float, 0x1C },
		{ "damageMultiplierTires", UID_float, 0x20 },
		{ "boundingBoxMin", UID_qVector3, 0x24 },
		{ "boundingBoxMAx", UID_qVector3, 0x30 },
		{ "tireShotImpulse", UID_float, 0x3C },
		{ "tireBlownImpulse", UID_float, 0x40 },
		{ "lowLodThrottleAcceleration", UID_float, 0x44 },
		{ "lowLodBrakesAcceleration", UID_float, 0x48 },
		{ "lowLodCoastAcceleration", UID_float, 0x4C },
		{ "lowLodMaxSpeed", UID_float, 0x50 },
		{ "lowLodMaxLateralAcceleration", UID_float, 0x54 },
		{ "lowLodMinTurningRadius", UID_float, 0x58 },
		{ "autoDeterioratingDamageThreshold", UID_float, 0x5C },
		{ "autoDeterioratingDamageRate", UID_float, 0x60 },
		{ "vehicleDistanceToHighLod", UID_float, 0x64 },
		{ "vehicleDistanceToMedLod", UID_float, 0x68 },
		{ "vehicleCollisionMinImpulseRequiredToTakeDamage", UID_float, 0x6C },
		{ "vehicleCollisionExtraDamageMultiplier", UID_float, 0x70 },
		{ "vehicleCollisionDamageDealtAtMinImpulse", UID_float, 0x74 },
		{ "vehicleCollisionDamageDealtAtMaxImpulse", UID_float, 0x78 },
		{ "vehicleCollisionMinImpulseRequiredToDealDamage", UID_float, 0x7C },
		{ "vehicleCollisionMaxImpulseForDealingDamage", UID_float, 0x80 },
		{ "vehicleCollisionDamageDealtAtMinRamImpulse", UID_float, 0x84 },
		{ "vehicleCollisionDamageDealtAtMaxRamImpulse", UID_float, 0x88 },
		{ "vehicleCollisionMinRamImpulseRequiredToDealDamage", UID_float, 0x8C },
		{ "vehicleCollisionMaxRamImpulseForDealingDamage", UID_float, 0x90 },
		{ "vehicleCollisionForceDamageDealer", UID_bool, 0x94 },
		{ "lockedAtLowLOD", UID_bool, 0x95 }
	}}},
	// component_BikePhysicsMover
	{ 0x3A19EBF5, { 0x14B9F38F, {
		{ "canWheelie", UID_int32, 0x98 }
	}}},
	// component_BoatPhysicsMover
	{ 0x1A07D10C, { 0x14B9F38F }},
	// component_CarPhysicsMover
	{ 0xF32DD55B, { 0x14B9F38F }},
	// component_VehicleAudio
	{ 0x77F43A25, { 0, {
		{ "AudioPropertySet", UID_qSymbol, 0 }
	}}},
	// component_VehicleEffects
	{ 0x83824245, { 0, {
		{ "headlightsInRainProbability", UID_float, 0 },
		{ "headlightsAlwaysOn", UID_bool, 0x4 },
		{ "headlightsAlwaysOff", UID_bool, 0x5 },
		{ "DamageTransfer", UID_qSymbolUC, 0x8 },
		{ "EffectGroupName", UID_qSymbolUC, 0xC },
		{ "InitialDirtSeed", UID_float, 0x10 },
		{ "GrimeFactor", UID_float, 0x14 },
		{ "Speed0", UID_float, 0x18 },
		{ "Speed1", UID_float, 0x1C },
		{ "Speed2", UID_float, 0x20 },
		{ "Speed3", UID_float, 0x24 }
	}}},
	// component_SimObjectProperties
	{ 0xC5AFD1A8, { 0, {
		{ "simObjectType", UID_qSymbol, 0 },
		{ "subTargetingProfile", UID_qSymbol, 0x4 }
	}}},
	// component_CharacterProperties
	{ 0xBF516446, { 0xC5AFD1A8, {
		{ "simObjectCharacterType", UID_qSymbol, 0x8 },
		{ "simObjectCharacterIsFemale", UID_bool, 0xC },
		{ "simObjectCharacterFightingClass", UID_qSymbol, 0x10 },
		{ "Stamina", UID_int32, 0x14 },
		{ "PoiCooldownTimeMin", UID_float, 0x18 },
		{ "PoiCooldownTimeMax", UID_float, 0x1C },
		{ "FactionClass", UID_qSymbol, 0x20 },
		{ "Gender", UID_qSymbol, 0x24 },
		{ "IsTired", UID_bool, 0x28 }
	}}},
	// component_VehicleProperties
	{ 0x7F1798C0, { 0xC5AFD1A8, {
		{ "simObjectVehicleType", UID_qSymbol, 0x8 },
		{ "simObjectBoatType", UID_qSymbol, 0xC },
		{ "aim_limit", UID_list, 0x10 },
		{ "default_left_aim_limit", UID_float, 0x18 },
		{ "default_right_aim_limit", UID_float, 0x1C },
		{ "door_phantom_info", UID_list, 0x20 }
	}}},
	// component_WeaponProperties
	{ 0x5454709E, { 0xC5AFD1A8 }},
	// component_ModelAsset
	{ 0x4BC08E82, { 0, {
		{ "ModelAssetName", UID_string, 0 },
		{ "ModelAssetId", UID_uint64, 0x8 }
	}}},
	// component_StreamedResource
	{ 0xDB4EBBFF, { 0, {
		{ "ResourceTags", UID_list, 0 },
		{ "ResourceList", UID_list, 0x8 },
		{ "ComponentList", UID_list, 0x10 },
		{ "TextureSetList", UID_list, 0x18 },
		{ "EntityType", UID_qSymbolUC, 0x20 },
		{ "TrueCrowdSelectionType", UID_uint32, 0x24 },
		{ "BMIMin", UID_float, 0x28 },
		{ "BMIMax", UID_float, 0x2C },
		{ "PartList", UID_list, 0x30 }
	}}},
	// component_Health
	{ 0xA9EB4546, { 0, {
		{ "maxUpgradedHealth", UID_int32, 0 },
		{ "maxHealth", UID_int32, 0x4 },
		{ "regenerativeHealthRate", UID_float, 0x8 },
		{ "InvulnerableCharacter", UID_bool, 0xC },
		{ "healthProjectileDamageMultiplier", UID_float, 0x10 }
	}}},
	// component_HitReaction
	{ 0x1575D886, { 0, {
		{ "HitActFilename", UID_string, 0 },
		{ "HitReactionOpeningBranchFullPath", UID_string, 0x8 },
		{ "HitReceiverDamageMultiplierPct", UID_uint32, 0x10 }
	}}},
	// component_Interactable
	{ 0xF20A4492, { 0, {
		{ "InteractionPoints", UID_list, 0 },
	}}},
	// component_InterestPoint
	{ 0x9B2B8283, { 0, {
		{ "InterestPointType", UID_qSymbol, 0 },
		{ "InterestPointPriority", UID_qSymbol, 0x4 },
		{ "StartActive", UID_bool, 0x8 },
		{ "Appeal", UID_float, 0xC },
		{ "MinAppealRadius", UID_float, 0x10 },
		{ "MaxAppealRadius", UID_float, 0x14 },
		{ "UserRelativeAngleRange", UID_float, 0x18 },
		{ "GenderAllowed", UID_qSymbol, 0x1C },
		{ "ChanceIsActive", UID_float, 0x20 },
		{ "TimeOfDayToBecomeActiveInHours", UID_float, 0x24 },
		{ "TimeOfDayToBecomeInactiveInHours", UID_float, 0x28 },
		{ "UseTimeMin", UID_float, 0x2C },
		{ "UseTimeMax", UID_float, 0x30 },
		{ "CoolDownTimeMin", UID_float, 0x34 },
		{ "CoolDownTimeMax", UID_float, 0x38 },
		{ "ItemFilterAppliesToPlayer", UID_bool, 0x3C },
		{ "ItemFilterOn", UID_bool, 0x3D },
		{ "ItemListIsAllowable", UID_bool, 0x3E },
		{ "ItemList", UID_list, 0x40 },
		{ "MaxConcurrentInstances", UID_int32, 0x48 },
		{ "MaxDistanceFromPlayer", UID_float, 0x4C },
		{ "SpawnAmbientUserDistance", UID_float, 0x50 },
		{ "IsAutoInteractable", UID_bool, 0x54 },
		{ "RequiresSync", UID_bool, 0x55 },
		{ "PositionSyncRequired", UID_bool, 0x56 },
		{ "RotationSyncRequired", UID_bool, 0x57 },
		{ "WeatherFilterOn", UID_bool, 0x58 },
		{ "WeatherFilterIsRaining", UID_bool, 0x59 },
		{ "AllowRepeatedUse", UID_bool, 0x5A },
		{ "AllowLeaders", UID_bool, 0x5B },
		{ "AllowFollowers", UID_bool, 0x5C },
		{ "MinGroupSize", UID_int32, 0x60 },
		{ "MaxGroupSize", UID_int32, 0x64 },
		{ "InitialUseOnly", UID_bool, 0x68 },
		{ "IgnoreCharacterCooldown", UID_bool, 0x69 },
		{ "UserCanBeRecycled", UID_bool, 0x6A },
		{ "ResumeIfInterrupted", UID_bool, 0x6B },
		{ "AllowSocialInteraction", UID_bool, 0x6C },
		{ "IsSittingConversation", UID_bool, 0x6D },
		{ "IgnoreStimuli", UID_bool, 0x6E }
	}}},
	// component_MissionFailCondition
	{ 0x91587106, { 0, {
		{ "ArrestFailTrigger", UID_bool, 0 },
		{ "DeathFailTrigger", UID_bool, 0x1 },
		{ "DamageFailTrigger", UID_bool, 0x2 },
		{ "DamageHealthThreshold", UID_float, 0x4 },
		{ "DistanceFailTrigger", UID_bool, 0x8 },
		{ "DistanceFailThreshold", UID_float, 0xC },
		{ "PanicWeaponFailTrigger", UID_bool, 0x10 },
		{ "PanicVehicleFailTrigger", UID_bool, 0x11 },
		{ "VehicleFlipFailTrigger", UID_bool, 0x12 },
		{ "BoatStuckFailTrigger", UID_bool, 0x13 },
		{ "ArrestFailCaption", UID_string, 0x18 },
		{ "DeathFailCaption", UID_string, 0x20 },
		{ "DamageFailCaption", UID_string, 0x28 },
		{ "DistanceFailCaption", UID_string, 0x30 },
		{ "PanicWeaponFailCaption", UID_string, 0x38 },
		{ "PanicVehicleFailCaption", UID_string, 0x40 },
		{ "VehicleFlipFailCaption", UID_string, 0x48 },
		{ "BoatStuckFailCaption", UID_string, 0x50 }
	}}},
	// component_Sensor
	{ 0x93D7F4B1, { 0, {
		{ "SensorPhantomSizeX", UID_float, 0 },
		{ "SensorPhantomSizeY", UID_float, 0x4 },
		{ "SensorPhantomSizeZ", UID_float, 0x8 },
		{ "HasActiveRegion", UID_bool, 0xC }
	}}},
	// object_physical_character_stats_BaseAttackParameters
	{ 0x8EA2B0B2, { 0, {
		{ "MaxDistanceToChooseCloseAttack", UID_float, 0 },
		{ "ExitDistanceForCloseAttack", UID_float, 0x4 },
		{ "MaxDistanceToChooseMidAttack", UID_float, 0x8 },
		{ "ExitDistanceForMidAttack", UID_float, 0xC },
		{ "MaxDistanceToUseCloseAttack", UID_float, 0x10 },
		{ "MaxDistanceToUseMidAttack", UID_float, 0x14 },
		{ "ChanceToUseMidAttack", UID_int32, 0x18 },
		{ "MinRunningAttackDistance", UID_float, 0x1C },
		{ "MaxRunningAttackDistance", UID_float, 0x20 },
		{ "RunningAttackExitDistance", UID_float, 0x24 },
		{ "MaxOpportunisticMeleeAttackDistanceVSPlayer", UID_float, 0x28 },
		{ "MaxOpportunisticMeleeAttackDistanceVSAI", UID_float, 0x2C },
		{ "MaxOpportunisticMeleeExitDistance", UID_float, 0x30 },
		{ "MaxOpportunityMeleeAttackDistanceVSPlayer", UID_float, 0x34 },
		{ "MaxOpportunityMeleeAttackDistanceVSAI", UID_float, 0x38 },
		{ "MaxOpportunityMeleeExitDistance", UID_float, 0x3C },
		{ "MinTimeBeforeOpportunityMeleeAttack", UID_float, 0x40 },
		{ "MaxTimeBeforeOpportunityMeleeAttack", UID_float, 0x44 },
		{ "MinForOpportunityMeleeAttackTimeout", UID_float, 0x48 },
		{ "MaxForOpportunityMeleeAttackTimeout", UID_float, 0x4C },
		{ "MaxOpportunityRangedAttackDistanceVSPlayer", UID_float, 0x50 },
		{ "MaxOpportunityRangedAttackDistanceVSAI", UID_float, 0x54 },
		{ "MaxOpportunityRangedExitDistance", UID_float, 0x58 },
		{ "MinTimeBeforeOpportunityRangedAttack", UID_float, 0x5C },
		{ "MaxTimeBeforeOpportunityRangedAttack", UID_float, 0x60 },
		{ "MinTimeBeforeNextOpportunityRangedAttack", UID_float, 0x64 },
		{ "MaxTimeBeforeNextOpportunityRangedAttack", UID_float, 0x68 },
		{ "InitialAttackTimeMinMeleeVSHumanAsEnemy", UID_float, 0x6C },
		{ "InitialAttackTimeMaxMeleeVSHumanAsEnemy", UID_float, 0x70 },
		{ "AttackTimeMinMeleeVSHumanAsEnemy", UID_float, 0x74 },
		{ "AttackTimeMaxMeleeVSHumanAsEnemy", UID_float, 0x78 },
		{ "AttackTimeMinMeleeVSHumanAsEnemyMobBattle", UID_float, 0x7C },
		{ "AttackTimeMaxMeleeVSHumanAsEnemyMobBattle", UID_float, 0x80 },
		{ "AttackTimeMinMeleeDownedVSHumanAsEnemy", UID_float, 0x84 },
		{ "AttackTimeMaxMeleeDownedVSHumanAsEnemy", UID_float, 0x88 },
		{ "InitialAttackTimeMinRangedVSHumanAsEnemy", UID_float, 0x8C },
		{ "InitialAttackTimeMaxRangedVSHumanAsEnemy", UID_float, 0x90 },
		{ "AttackTimeMinRangedVSHumanAsEnemy", UID_float, 0x94 },
		{ "AttackTimeMaxRangedVSHumanAsEnemy", UID_float, 0x98 },
		{ "AttackTimeMinRangedDownedVSHumanAsEnemy", UID_float, 0x9C },
		{ "AttackTimeMaxRangedDownedVSHumanAsEnemy", UID_float, 0xA0 },
		{ "InitialAttackTimeMinRangedInCoverVSHumanAsEnemy", UID_float, 0xA4 },
		{ "InitialAttackTimeMaxRangedInCoverVSHumanAsEnemy", UID_float, 0xA8 },
		{ "AttackTimeMinRangedInCoverVSHumanAsEnemy", UID_float, 0xAC },
		{ "AttackTimeMaxRangedInCoverVSHumanAsEnemy", UID_float, 0xB0 },
		{ "AttackTimeMinRangedInCoverDownedVSHumanAsEnemy", UID_float, 0xB4 },
		{ "AttackTimeMaxRangedInCoverDownedVSHumanAsEnemy", UID_float, 0xB8 },
		{ "InitialAttackTimeMinDirectFollowersVSHumanAsEnemy", UID_float, 0xBC },
		{ "InitialAttackTimeMaxDirectFollowersVSHumanAsEnemy", UID_float, 0xC0 },
		{ "AttackTimeMinDirectFollowersVSHumanAsEnemy", UID_float, 0xC4 },
		{ "AttackTimeMaxDirectFollowersVSHumanAsEnemy", UID_float, 0xC8 },
		{ "AttackTimeMinDirectFollowersDownedVSHumanAsEnemy", UID_float, 0xCC },
		{ "AttackTimeMaxDirectFollowersDownedVSHumanAsEnemy", UID_float, 0xD0 },
		{ "InitialAttackTimeMinMeleeVSAIAsEnemy", UID_float, 0xD4 },
		{ "InitialAttackTimeMaxMeleeVSAIAsEnemy", UID_float, 0xD8 },
		{ "AttackTimeMinMeleeVSAIAsEnemy", UID_float, 0xDC },
		{ "AttackTimeMaxMeleeVSAIAsEnemy", UID_float, 0xE0 },
		{ "AttackTimeMinMeleeDownedVSAIAsEnemy", UID_float, 0xE4 },
		{ "AttackTimeMaxMeleeDownedVSAIAsEnemy", UID_float, 0xE8 },
		{ "InitialAttackTimeMinRangedVSAIAsEnemy", UID_float, 0xEC },
		{ "InitialAttackTimeMaxRangedVSAIAsEnemy", UID_float, 0xF0 },
		{ "AttackTimeMinRangedVSAIAsEnemy", UID_float, 0xF4 },
		{ "AttackTimeMaxRangedVSAIAsEnemy", UID_float, 0xF8 },
		{ "AttackTimeMinRangedDownedVSAIAsEnemy", UID_float, 0xFC },
		{ "AttackTimeMaxRangedDownedVSAIAsEnemy", UID_float, 0x100 },
		{ "InitialAttackTimeMinRangedInCoverVSAIAsEnemy", UID_float, 0x104 },
		{ "InitialAttackTimeMaxRangedInCoverVSAIAsEnemy", UID_float, 0x108 },
		{ "AttackTimeMinRangedInCoverVSAIAsEnemy", UID_float, 0x10C },
		{ "AttackTimeMaxRangedInCoverVSAIAsEnemy", UID_float, 0x110 },
		{ "AttackTimeMinRangedInCoverDownedVSAIAsEnemy", UID_float, 0x114 },
		{ "AttackTimeMaxRangedInCoverDownedVSAIAsEnemy", UID_float, 0x118 },
		{ "InitialAttackTimeMinDirectFollowersVSAIAsEnemy", UID_float, 0x11C },
		{ "InitialAttackTimeMaxDirectFollowersVSAIAsEnemy", UID_float, 0x120 },
		{ "AttackTimeMinDirectFollowersVSAIAsEnemy", UID_float, 0x124 },
		{ "AttackTimeMaxDirectFollowersVSAIAsEnemy", UID_float, 0x128 },
		{ "AttackTimeMinDirectFollowersDownedVSAIAsEnemy", UID_float, 0x12C },
		{ "AttackTimeMaxDirectFollowersDownedVSAIAsEnemy", UID_float, 0x130 },
		{ "InitialAttackTimeMinMeleeVSAIAsAlly", UID_float, 0x134 },
		{ "InitialAttackTimeMaxMeleeVSAIAsAlly", UID_float, 0x138 },
		{ "AttackTimeMinMeleeVSAIAsAlly", UID_float, 0x13C },
		{ "AttackTimeMaxMeleeVSAIAsAlly", UID_float, 0x140 },
		{ "AttackTimeMinMeleeDownedVSAIAsAlly", UID_float, 0x144 },
		{ "AttackTimeMaxMeleeDownedVSAIAsAlly", UID_float, 0x148 },
		{ "InitialAttackTimeMinRangedVSAIAsAlly", UID_float, 0x14C },
		{ "InitialAttackTimeMaxRangedVSAIAsAlly", UID_float, 0x150 },
		{ "AttackTimeMinRangedVSAIAsAlly", UID_float, 0x154 },
		{ "AttackTimeMaxRangedVSAIAsAlly", UID_float, 0x158 },
		{ "AttackTimeMinRangedDownedVSAIAsAlly", UID_float, 0x15C },
		{ "AttackTimeMaxRangedDownedVSAIAsAlly", UID_float, 0x160 },
		{ "InitialAttackTimeMinRangedInCoverVSAIAsAlly", UID_float, 0x164 },
		{ "InitialAttackTimeMaxRangedInCoverVSAIAsAlly", UID_float, 0x168 },
		{ "AttackTimeMinRangedInCoverVSAIAsAlly", UID_float, 0x16C },
		{ "AttackTimeMaxRangedInCoverVSAIAsAlly", UID_float, 0x170 },
		{ "AttackTimeMinRangedInCoverDownedVSAIAsAlly", UID_float, 0x174 },
		{ "AttackTimeMaxRangedInCoverDownedVSAIAsAlly", UID_float, 0x178 },
		{ "InitialAttackTimeMinDirectFollowersVSAIAsAlly", UID_float, 0x17C },
		{ "InitialAttackTimeMaxDirectFollowersVSAIAsAlly", UID_float, 0x180 },
		{ "AttackTimeMinDirectFollowersVSAIAsAlly", UID_float, 0x184 },
		{ "AttackTimeMaxDirectFollowersVSAIAsAlly", UID_float, 0x188 },
		{ "AttackTimeMinDirectFollowersDownedVSAIAsAlly", UID_float, 0x18C },
		{ "AttackTimeMaxDirectFollowersDownedVSAIAsAlly", UID_float, 0x190 }
	}}},
	// component_ColourTint
	{ 0x5AC530F1, { 0, {
		{ "ColourTint_Instance", UID_qVector4, 0 },
		{ "ColourTintSI_Instance", UID_qVector4, 0x10 }
	}}},
	// component_CompositeDrawable
	{ 0x79DB63A1, { 0, {
		{ "DefaultSaturationOverride", UID_float, 0 },
		{ "LightSFXMultiplier", UID_float, 0x4 },
		{ "HighlightingMode", UID_string, 0x8 },
		{ "HighlightingColour", UID_qVector4, 0x10 },
		{ "SkinSSEnabled", UID_bool, 0x20 },
		{ "OverlayWeights", UID_list, 0x28 },
		{ "OverlayTextures", UID_list, 0x30 },
		{ "DrawScale", UID_float, 0x38 }
	}}},
	// component_DropShadow
	{ 0xEC2CE6F9, { 0, {
		{ "DropShadow_ScaleX", UID_float, 0 },
		{ "DropShadow_ScaleY", UID_float, 0x4 },
		{ "DropShadow_TextureUID", UID_qSymbolUC, 0x8 }
	}}},
	// component_DynamicLight
	{ 0xD5C37399, { 0, {
		{ "Light_Color", UID_qVector3, 0 },
		{ "Light_Intensity", UID_float, 0xC },
		{ "Light_Attenuation", UID_float, 0x10 },
		{ "Light_DecayRadius", UID_float, 0x14 },
		{ "Light_FovInner", UID_float, 0x18 },
		{ "Light_FovOuter", UID_float, 0x1C },
		{ "Light_ShadowNear", UID_float, 0x20 },
		{ "Light_AreaWidth", UID_float, 0x24 },
		{ "Light_AreaHeight", UID_float, 0x28 },
		{ "Light_AreaOffset", UID_float, 0x2C },
		{ "Light_AreaFarOffset", UID_float, 0x30 },
		{ "Light_OnTime", UID_float, 0x34 },
		{ "Light_OffTime", UID_float, 0x38 },
		{ "Light_TextureUID", UID_qSymbolUC, 0x3C },
		{ "Light_TexDistAttenUID", UID_qSymbolUC, 0x40 },
		{ "Light_TexDistAtten_V", UID_float, 0x44 },
		{ "Light_Specular", UID_bool, 0x48 },
		{ "Light_Shadow", UID_bool, 0x49 },
		{ "Light_Type", UID_uint32, 0x4C }
	}}},
	// component_FacialActionTree
	{ 0x8607C0B, { 0, {
		{ "FacialActFileName", UID_string, 0 }
	}}},
	// component_FormationManager
	{ 0x8259C690, { 0, {
		{ "NumRanges", UID_int32, 0 },
		{ "NumSlotsInRange0", UID_int32, 0x4 },
		{ "NumSlotsInRange1", UID_int32, 0x8 },
		{ "NumSlotsInRange2", UID_int32, 0xC },
		{ "NumSlotsInRange3", UID_int32, 0x10 },
		{ "NormalMaxDistance0", UID_float, 0x14 },
		{ "NormalMaxDistance1", UID_float, 0x18 },
		{ "NormalMaxDistance2", UID_float, 0x1C },
		{ "NormalMaxDistance3", UID_float, 0x20 },
		{ "NormalMinTimeBeforeCheckPlayersTarget", UID_float, 0x24 },
		{ "NormalMaxTimeBeforeCheckPlayersTarget", UID_float, 0x28 },
		{ "NormalMinTimeBeforeSwitchFromRange0", UID_float, 0x2C },
		{ "NormalMaxTimeBeforeSwitchFromRange0", UID_float, 0x30 },
		{ "NormalMinTimeBeforeSwitchFromRange1", UID_float, 0x34 },
		{ "NormalMaxTimeBeforeSwitchFromRange1", UID_float, 0x38 },
		{ "NormalMinTimeBeforeSwitchFromRange2", UID_float, 0x3C },
		{ "NormalMaxTimeBeforeSwitchFromRange2", UID_float, 0x40 },
		{ "MobMaxDistance0", UID_float, 0x44 },
		{ "MobMaxDistance1", UID_float, 0x48 },
		{ "MobMaxDistance2", UID_float, 0x4C },
		{ "MobMaxDistance3", UID_float, 0x50 },
		{ "MobMinTimeBeforeCheckPlayersTarget", UID_float, 0x54 },
		{ "MobMaxTimeBeforeCheckPlayersTarget", UID_float, 0x58 },
		{ "MobMinTimeBeforeSwitchFromRange0", UID_float, 0x5C },
		{ "MobMaxTimeBeforeSwitchFromRange0", UID_float, 0x60 },
		{ "MobMinTimeBeforeSwitchFromRange1", UID_float, 0x64 },
		{ "MobMaxTimeBeforeSwitchFromRange1", UID_float, 0x68 },
		{ "MobMinTimeBeforeSwitchFromRange2", UID_float, 0x6C },
		{ "MobMaxTimeBeforeSwitchFromRange2", UID_float, 0x70 },
		{ "MaxRadialDistanceFromDesiredPosition0", UID_float, 0x74 },
		{ "MaxRadialDistanceFromDesiredPositionHysteresis0", UID_float, 0x78 },
		{ "MaxRadialDistanceFromDesiredPositionHysteresisLarge0", UID_float, 0x7C },
		{ "MaxLateralDistanceFromDesiredPosition0", UID_float, 0x80 },
		{ "MaxLateralDistanceFromDesiredPositionHysteresis0", UID_float, 0x84 },
		{ "MaxRadialDistanceFromDesiredPosition1", UID_float, 0x88 },
		{ "MaxRadialDistanceFromDesiredPositionHysteresis1", UID_float, 0x8C },
		{ "MaxRadialDistanceFromDesiredPositionHysteresisLarge1", UID_float, 0x90 },
		{ "MaxLateralDistanceFromDesiredPosition1", UID_float, 0x94 },
		{ "MaxLateralDistanceFromDesiredPositionHysteresis1", UID_float, 0x98 },
		{ "MaxRadialDistanceFromDesiredPosition2", UID_float, 0x9C },
		{ "MaxRadialDistanceFromDesiredPositionHysteresis2", UID_float, 0xA0 },
		{ "MaxRadialDistanceFromDesiredPositionHysteresisLarge2", UID_float, 0xA4 },
		{ "MaxLateralDistanceFromDesiredPosition2", UID_float, 0xA8 },
		{ "MaxLateralDistanceFromDesiredPositionHysteresis2", UID_float, 0xAC },
		{ "MaxRadialDistanceFromDesiredPosition3", UID_float, 0xB0 },
		{ "MaxRadialDistanceFromDesiredPositionHysteresis3", UID_float, 0xB4 },
		{ "MaxRadialDistanceFromDesiredPositionHysteresisLarge3", UID_float, 0xB8 },
		{ "MaxLateralDistanceFromDesiredPosition3", UID_float, 0xBC },
		{ "MaxLateralDistanceFromDesiredPositionHysteresis3", UID_float, 0xC0 },
		{ "MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting", UID_float, 0xC4 },
		{ "FacingTypeEnumString", UID_string, 0xC8 },
		{ "MaxFacingDifference0", UID_float, 0xD0 },
		{ "MaxFacingDifferenceHysteresis0", UID_float, 0xD4 },
		{ "MaxFacingDifference1", UID_float, 0xD8 },
		{ "MaxFacingDifferenceHysteresis1", UID_float, 0xDC },
		{ "MaxFacingDifference2", UID_float, 0xE0 },
		{ "MaxFacingDifferenceHysteresis2", UID_float, 0xE4 },
		{ "MaxFacingDifference3", UID_float, 0xE8 },
		{ "MaxFacingDifferenceHysteresis3", UID_float, 0xEC },
		{ "RadialHysteresisModifierMin0", UID_float, 0xF0 },
		{ "RadialHysteresisModifierMax0", UID_float, 0xF4 },
		{ "RadialHysteresisModifierMin1", UID_float, 0xF8 },
		{ "RadialHysteresisModifierMax1", UID_float, 0xFC },
		{ "RadialHysteresisModifierMin2", UID_float, 0x100 },
		{ "RadialHysteresisModifierMax2", UID_float, 0x104 },
		{ "RadialHysteresisModifierMin3", UID_float, 0x108 },
		{ "RadialHysteresisModifierMax3", UID_float, 0x10C }
	}}},
	// component_FXSimComponent
	{ 0x6FE755E1, { 0, {
		{ "EffectId", UID_qSymbolUC, 0 }
	}}},
	// component_InventoryItem
	{ 0x9DA2A4AD, { 0, {
		{ "InventoryItemQuantityMin", UID_uint32, 0 },
		{ "InventoryItemQuantityMax", UID_uint32, 0x4 },
		{ "simObjectInventoryItem", UID_qSymbol, 0x8 }
	}}},
	// component_IrradianceVolume
	{ 0xFF8F4170, { 0, {
		{ "IrrVol_ResolutionX", UID_uint32, 0 },
		{ "IrrVol_ResolutionY", UID_uint32, 0x4 },
		{ "IrrVol_ResolutionZ", UID_uint32, 0x8 },
		{ "IrrVol_Type", UID_uint32, 0xC },
		{ "IrrVol_Flags", UID_uint32, 0x10 },
		{ "IrrVol_Max", UID_qVector3, 0x14 },
		{ "IrrVol_Min", UID_qVector3, 0x20 },
		{ "IrrVol_Id", UID_uint64, 0x30 },
		{ "IrrVol_SectionIndex", UID_int32, 0x38 }
	}}},
	// component_Prefab
	{ 0x67BC1D2A, { 0, {
		{ "PrefabId", UID_qSymbol, 0 }
	}}},
	// component_Spawn
	{ 0x979B8346, { 0, {
		{ "Spawn_Pad0", UID_bool, 0 },
		{ "Spawn_Pad1", UID_bool, 0x1 },
		{ "Spawn_Pad2", UID_bool, 0x2 },
		{ "Spawn_Pad3", UID_bool, 0x3 }
	}}},
	// component_SpawnPoint
	{ 0x13077530, { 0, {
		{ "DeferSpawning", UID_bool, 0 },
		{ "ThugPoint", UID_bool, 0x1 }
	}}},
	// component_SpawnRegion
	{ 0xE7534509, { 0x979B8346, {
		{ "SpawnInfo", UID_qSymbol, 0x4 },
		{ "SpawnPopulation", UID_int32, 0x8 },
		{ "TimeSet", UID_qSymbol, 0xC },
		{ "ThugRegion", UID_bool, 0x10 }
	}}},
	// component_TSActor
	{ 0x2873821B, { 0, {
		{ "SkookumClass", UID_qSymbol, 0 }
	}}},
	// component_WorldContext
	{ 0xA59FE5E4, { 0, {
		{ "WC_StinkyFeet", UID_int32, 0 }
	}}}
};