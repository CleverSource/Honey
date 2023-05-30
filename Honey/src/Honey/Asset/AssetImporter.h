#pragma once

#include "AssetMetadata.h"

namespace Honey {

	class AssetImporter
	{
	public:
		static Ref<Asset> ImportAsset(AssetHandle handle, const AssetMetadata& metadata);
	};

}
