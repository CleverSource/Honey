#pragma once

#include "Asset.h"
#include "AssetMetadata.h"

#include "Honey/Renderer/Texture.h"

namespace Honey {

	class TextureImporter
	{
	public:
		static Ref<Texture2D> ImportTexture2D(AssetHandle handle, const AssetMetadata& metadata);
	};

}
