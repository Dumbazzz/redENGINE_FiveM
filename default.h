#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

#include "font_awesome.h"

#include <Windows.h>
#include <iostream>
#include <vector>

#include "gui.h"

namespace Default
{
	void Render()
	{
		ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 1.3);
		ImGui::Text("Default");
		Gui::Seperator("##default_seperator_1");
		ImGui::Text("No section has been selected. Click a button on the left navbar.");
	}
}