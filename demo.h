#pragma once

#include "imgui/imgui_internal.h"
#include "imgui/imgui.h"

#include <Windows.h>
#include <vector>
#include <iostream>

namespace Demo
{
	// i just made this file just cause if you're not good at imgui, then you can use this lmfao

	bool ShowDemo = true;
	bool TestCheckBox = true;

	//Note: doing ##label, is just the id of your object / item etc etc.
	

	static int SelectedListBoxItem = NULL;
	const char* ListBoxArrayDemo[] = {"Demo Item 1","Demo Item 2","Demo Item 3"};

	static int SelectedComboItem = NULL;
	const char* ComboBoxArrayDemo[] = { "Demo Item 1","Demo Item 2","Demo Item 3" };

	static char InputTextDemo[256] = "";
	static char InputTextWithHintDemo[256] = "";
	static char PasswordInputTextDemo[256] = "";
	static char InputTextMultiLineDemo[4096] = "";

	void Render()
	{
		ImGui::Separator();
		ImGui::Columns(2); // Creating 2 columns
		ImGui::SetColumnOffset(1, ImGui::GetWindowWidth() / 2); // comment this out if you want to be able to move the column around :)
		ImGui::Checkbox("TestBox", &TestCheckBox);
		ImGui::PushItemWidth(ImGui::GetWindowWidth() / 3);  //ImGui::PushItemWidth(float item_width) just expands the item width
		ImGui::ListBox("##ListBoxDemo", &SelectedListBoxItem, ListBoxArrayDemo, IM_ARRAYSIZE(ListBoxArrayDemo));
		ImGui::PopItemWidth(); //If you don't pop the items width after you call the 'ImGui::PushItemWidth(float item_width)' function, you will get an error

		ImGui::Button("My Button"); // Just a button with no custom size etc, it just defaults
		ImGui::Button("My custom sized button", ImVec2(200, 30)); // We added a 'ImVec2' which is just x & y coords. The first param of ImVec2 is an x value(item width) and the second is a y value(item height).
		if (ImGui::Button("If ImGui::Button", ImVec2(200, 30)))
		{
			// If the button is pressed then... do your code.
		}

		ImGui::Text("My custom text"); // This only takes 1 param, just some text lol

		ImGui::TextColored(ImColor(255, 0, 0, 255), "My Custom Red Color Text!"); // Colored text, just takes 2 params, A ImVec4 color & text.

		ImGui::Text("Hover me!");
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("This is a custom tool tip!");

		ImGui::PushItemWidth(ImGui::GetWindowWidth() / 3);
		ImGui::Combo("##DemoCombo", &SelectedComboItem, ComboBoxArrayDemo, IM_ARRAYSIZE(ComboBoxArrayDemo));
		ImGui::PopItemWidth();

		ImGui::NextColumn(); // The other side of the column

		ImGui::SetCursorPosX(500); // Set the (X) position of your item, change 100 to your (X) position.
		ImGui::Text("Custom X positioned text!");

		ImGui::SetCursorPosY(100); // Set the (Y) position of your item, change 100 to your (Y) position.
		ImGui::Text("Custom Y positioned text!");



		ImGui::InputText("##InputTextDemo", InputTextDemo, IM_ARRAYSIZE(InputTextDemo)); 
		ImGui::SameLine(); // puts the button called 'Output' beside the input text
		if (ImGui::Button("Output"))
		{
			MessageBoxA(NULL, InputTextDemo, "Custom TextBox Lol.", NULL);
		}
		ImGui::InputTextWithHint("##InputTextWithHintDemo", "Type stuff here...", InputTextWithHintDemo, IM_ARRAYSIZE(InputTextWithHintDemo));
		ImGui::InputTextWithHint("##PasswordInputTextDemo", "Enter your secret password." , PasswordInputTextDemo, IM_ARRAYSIZE(PasswordInputTextDemo), ImGuiInputTextFlags_Password); //replaces your text you type with *
		ImGui::InputTextMultiline("##InputTextMultiLineDemo", InputTextMultiLineDemo, IM_ARRAYSIZE(InputTextMultiLineDemo), ImVec2(ImGui::GetWindowWidth() / 2, 80));

	}
}