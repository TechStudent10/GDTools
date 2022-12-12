#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "mainpopup.hpp"

USE_GEODE_NAMESPACE();

class $modify(MenuLayer) {
	void onMoreGames(CCObject*) {
		// FLAlertLayer::create("Geode", "Hello from my custom mod!", "OK")->show(); 
		MainPopup::create()->show();
	} 
};
