#include <Geode/Geode.hpp>

#ifndef MAINPOPUP_H
#define MAINPOPUP_H

class MainPopup : public geode::Popup<> {
    protected:
        bool setup() override;
    public:
        static MainPopup* create();
        void toggleNoclip(CCObject*);
};

#endif