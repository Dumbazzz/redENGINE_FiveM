#pragma once
#include "imgui/imgui.h"
#include "TextEditor.h"
#include "font_awesome.h"
#include <vector>

TextEditor editor;

static int selectedResource = NULL;
std::vector<const char*> resources = {
	"_cfx_internal","fivem","hardcap","anti-cheese","esx_mafia","esx_gopostal","esx_jail","mysql-async","es_admin2",
	"async","es_extended","esx_barbershop","esx_clotheshop","esx_datastore","esx_garage","esx_identity","esx_lscustom",
	"esx_menu_default","esx_menu_dialog","esx_menu_list","esx_property","esx_shops","esx_sit","esx_vehicleshop","esx_weashops",
	"es_camera","instance","skinchanger","mellotrainer","bob74_ipl","coordsaver","loadingscreen"
};


namespace Executor
{
	void Render()
	{
		auto size = ImGui::GetWindowSize();
		editor.SetReadOnly(false);
		editor.SetShowWhitespaces(false);
		editor.SetPalette(TextEditor::GetDarkPalette());
		ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 1.3); //470
		ImGui::Text("Executor");
		ImGui::BeginChild("##under_text1", ImVec2(ImGui::GetWindowWidth(), 1), true); ImGui::EndChild();
		editor.Render("##Null", ImVec2(size.x - 16, size.y - 110), true);ImGui::Spacing();
		if (ImGui::Button(ICON_FA_CODE" Execute", ImVec2(116, 30)))
		{
			if (resources[selectedResource] == "_cfx_internal")
			{
				MessageBoxA(NULL, "You can't execute in _cfx_interal", "redENGINE", MB_OK | MB_ICONERROR);
				return;
			}
			else
			{
				
			}
		}	
		ImGui::SameLine();
		if (ImGui::Button(ICON_FA_FILE" Load from File", ImVec2(180, 30)))
		{
			// load file code
		}
			
		ImGui::SameLine();
		ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
		ImGui::Combo("##resources", &selectedResource, resources.data(), resources.size());
		ImGui::PopItemWidth();
				
	}
}