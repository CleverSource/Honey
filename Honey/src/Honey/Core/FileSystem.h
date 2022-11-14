#pragma once

#include "Honey/Core/Buffer.h"

namespace Honey {

	class FileSystem
	{
	public:
		// TODO: move to FileSystem class
		static Buffer ReadFileBinary(const std::filesystem::path& filepath);
	};

}
