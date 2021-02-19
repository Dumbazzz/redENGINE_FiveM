#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

#include "font_awesome.h"

#include <Windows.h>
#include <iostream>
#include <vector>

#include "gui.h"

std::vector<const char*> FreeMenus = { 
"HoaX_2.0",
"Lynx_8.1",
"Lynx_10.0",
"InSec_1.0",
"SkidMenu_1.0",
"TiagoMenu_3.0",
"TiagoMenu_4.0",
"TiagoMenu_4.1",
"Strata_1.0",
"Lydia_Enterprise" 
};

std::vector<const char*> PremMenus = {
"Lux",
"Dopamine",
"Absolute",
"Reaper",
"Fallout",
};

static int SelectedFreeMenu = NULL;
static int SelectedPremMenu = NULL;

namespace Menus
{
	void Render()
	{
		ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 1.3);
		ImGui::Text("Menus");
		Gui::Seperator("##menus_seperator_1");
		ImGui::NewLine();

		//FreeMenus
		ImGui::BeginChild("##freemenus_side", ImVec2(ImGui::GetWindowWidth() / 2.8, ImGui::GetWindowHeight()), false);

		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 75);
		ImGui::Text(ICON_FA_HOME" Free Menus " ICON_FA_HOME);
		Gui::Seperator("##freemenus_seperator_1");
		ImGui::ListBoxHeader("##freemenusbox", ImVec2(ImGui::GetWindowWidth(), 300));

		for (int i = 0; i < FreeMenus.size(); i++)
		{
			const bool is_selected = (SelectedFreeMenu == i);
			if (ImGui::Selectable(FreeMenus[i], is_selected))
				SelectedFreeMenu = i;
		}
		ImGui::ListBoxFooter();

		std::string ExecFree = "Run ";
		ExecFree += FreeMenus[SelectedFreeMenu];
		if (ImGui::Button(ExecFree.c_str(), ImVec2(ImGui::GetWindowWidth(), 33)))
		{

		}

		ImGui::EndChild();

		ImGui::SameLine();
		Gui::Seperator("##splitter_2", 1, ImGui::GetWindowHeight(),false);
		ImGui::SameLine();

		//Premium Menus
		ImGui::BeginChild("##premmenus_side", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetWindowHeight()), false);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 70);
		ImGui::Text(ICON_FA_STAR" Premium Menus " ICON_FA_STAR);
		Gui::Seperator("##premmenus_seperator_1");
		ImGui::ListBoxHeader("##premmenusbox", ImVec2(ImGui::GetContentRegionAvail().x, 300));

		for (int i = 0; i < PremMenus.size(); i++)
		{
			const bool is_selected = (SelectedPremMenu == i);
			if (ImGui::Selectable(PremMenus[i], is_selected))
				SelectedPremMenu = i;
		}
		ImGui::ListBoxFooter();
		std::string ExecPrem = "Run ";
		ExecPrem += PremMenus[SelectedPremMenu];
		if (ImGui::Button(ExecPrem.c_str(), ImVec2(ImGui::GetWindowWidth(), 33)))
		{

		}
		ImGui::EndChild();

	
		
		


		

	}
}