#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include "mainpopup.hpp"
#include <map>

USE_GEODE_NAMESPACE();

// typedef std::map<std::string, std::string> BasePairMap;

// BasePairMap settings;
// std::string settings["noclip"] = "false";

bool noclipenabled = false;

class $(PlayLayer) {
	void destroyPlayer(PlayerObject* playerObject, GameObject* gameObject) {
        if (!noclipenabled) {
            PlayLayer::destroyPlayer(playerObject, gameObject);
        }
    }
};

void MainPopup::toggleNoclip(CCObject* sender) {
    // settings["noclip"] = (settings["noclip"] == "false") ? "true" : "false";
    noclipenabled = !noclipenabled;
}

auto testNoclip(CCSprite* toggleOn, CCSprite* toggleOff) {
    return (noclipenabled) ? toggleOn : toggleOff;
}

bool MainPopup::setup() {
    m_noElasticity = true;

    auto winSize = CCDirector::sharedDirector()->getWinSize();
    // convenience function provided by Popup 
    // for adding/setting a title to the popup
    this->setTitle("GDTools");

    auto toggleOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
    auto toggleOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");

    auto noclipBtn = CCMenuItemToggler::create(testNoclip(toggleOn, toggleOff), testNoclip(toggleOff, toggleOn), this, menu_selector(MainPopup::toggleNoclip));
    
    // auto noclipBtn = CCMenuItemSpriteExtra::create(
    //     testNoclip(toggleOn, toggleOff), this, menu_selector(MainPopup::toggleNoclip)
    // );

    auto label = CCLabelBMFont::create("NoClip", "goldfont.fnt");

    noclipBtn->setScale(0.5F);
    label->setScale(0.5F);
    label->setPositionX(45);
    auto menu = CCMenu::create();
    menu->addChild(noclipBtn);
    menu->addChild(label);

    this->addChild(menu);

    // auto label = CCLabelBMFont::create("testing lol", "bigFont.fnt");
    // label->setPosition(winSize / 2);
    // this->addChild(label);

    return true;
};

MainPopup* MainPopup::create() {
    auto ret = new MainPopup();
    if (ret && ret->init(240.f, 160.f)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
};
