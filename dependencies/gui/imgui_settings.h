#pragma once

#include "imgui.h"

namespace c {

	namespace picker
	{
		inline ImVec4 background = ImColor(200, 0, 200, 255);
		inline ImVec4 outline = ImColor(255, 0, 255, 255);

		inline float rounding = 2.f;
	}

	namespace child
	{

		inline ImVec4 background = ImColor(200, 0, 200, 255);
		inline ImVec4 outline = ImColor(255, 0, 255, 255);
		inline float rounding = 8.f;

	}

	namespace text
	{
		inline ImVec4 text_active = ImColor(190, 131, 194, 255);
		inline ImVec4 text_hov = ImColor(190, 131, 194, 255);
		inline ImVec4 text = ImColor(190, 131, 194, 255);

		inline float glow_size = 8.f;
	}

}