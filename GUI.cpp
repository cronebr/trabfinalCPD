#include "GUI.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main(array<String^>^arg) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TrabalhoCPD::GUI form;
	Application::Run(%form);
}