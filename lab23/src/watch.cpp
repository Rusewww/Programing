#include "watch.h"

#include <utility>

manufacturerStruct::manufacturerStruct()
{
	firm = "empty";
	country = "empty";
}

manufacturerStruct::manufacturerStruct(string firmClone, string countryClone)
{
	firm = std::move(firmClone);
	country = std::move(countryClone);
}

manufacturerStruct::manufacturerStruct(const manufacturerStruct &clone)
{
	firm = clone.firm;
	country = clone.country;
}

manufacturerStruct::~manufacturerStruct() = default;

watch::watch()
{
	waterproof = false;
	model = "empty";
	cost = 0;
	watch::manufacturer = manufacturerStruct();
	style = ARMOURED;
}

watch::watch(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct& manufacturerClone, watchStyle styleClone)
{
	waterproof = waterproofClone;
	model = std::move(modelClone);
	cost = costClone;
	watch::manufacturer = manufacturerStruct(manufacturerClone);
	style = styleClone;
}

watch::watch(const watch &clone)
{
	waterproof = clone.waterproof;
	model = clone.model;
	cost = clone.cost;
	watch::manufacturer = manufacturerStruct(clone.manufacturer);
	style = clone.style;
}

watch::~watch() = default;