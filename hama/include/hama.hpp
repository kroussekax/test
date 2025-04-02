#pragma once

// from hama
#include "level.hpp"

namespace hama{
class LevelEditor{
private:
	char level_name[32];
	j3e::Level level;
public:
	LevelEditor();
};
};
