#pragma once

#include "imgui/imgui_internal.h"
#include "imgui/imgui.h"

#include <Windows.h>
#include <vector>
#include <iostream>
#include "font_awesome.h"

#include "gui.h"

using namespace std;
static bool Safemode = true;
static bool ShBypass = true;

namespace Config
{


	void Render()
	{
		ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 1.3);
		ImGui::Text("Config");
		Gui::Seperator("##config_seperator_0");
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 30);

		ImGui::SetCursorPosX(233);
		ImGui::BeginChild("##config_side", ImVec2(ImGui::GetWindowWidth() / 3, ImGui::GetWindowHeight()), false);

		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 83);
		ImGui::Text("Safe Mode"); 
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 0, 0, 255), "(?)"); ImGui::Spacing();
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Safe mode creates a private scripting environment which anti-cheats cannot attach to.");

		Gui::Seperator("##config_seperator_1", ImGui::GetWindowWidth());

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 7));
		ImGui::Checkbox("Enabled", &Safemode);
		ImGui::PopStyleVar();

		Gui::Seperator("##config_seperator_2", ImGui::GetWindowWidth());
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 57);
		ImGui::Text("ScriptHook Bypass"); 
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 0, 0, 255), "(?)"); ImGui::Spacing();
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("ScriptHook Bypass allows you to use .ASI menus which are completely undetected from any anti cheat.");

		Gui::Seperator("##config_seperator_3", ImGui::GetWindowWidth());
		//ImGui::TextColored(ImColor(255, 0, 0, 255), "Currently disabled..."); //uncomment this if rE sh bypass doesn't work xD
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 7));
		ImGui::Checkbox("Enabled", &ShBypass);
		ImGui::PopStyleVar();

		Gui::Seperator("##config_seperator_4", ImGui::GetWindowWidth());

		ImGui::EndChild();
		ImGui::SameLine();
		Gui::Seperator("##splitter", 1, ImGui::GetWindowHeight());
		ImGui::SameLine();
		ImGui::BeginChild("##server_side", ImVec2(ImGui::GetWindowWidth(), ImGui::GetWindowHeight()), false);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 58);
		ImGui::Text("Server related stuff");
		ImGui::Spacing();
		Gui::Seperator("##server_seperator_1", ImGui::GetWindowWidth());
		ImGui::Text("Server IP: 127.0.0.1");
		Gui::Seperator("##server_seperator_2", ImGui::GetWindowWidth());
		ImGui::EndChild();
		


	}
}