#include "main.hpp"

void App::OnPreRender()
{	
	stats	<< "Sprite ID: " 	<< rings.rend.Spr()->Name()
		 	<< " Flip State: " 	<< rings.rend.Spr()->Flip()
		 	<< " X: " 			<< rings.rend.Spr()->XaOrig()
		 	<< " Y: " 			<< rings.rend.Spr()->YaOrig()
			<< " Frame: "		<< pF
			<< " Held: " 		<< rings.input.k_swit.Held();

	rings.Update();

	statstext.Load(graphicsRenderer, stats.str().c_str(), *gfont);

	stats.flush();
	stats.str("");
}
