#include "MainWindow.h"

MainWindow::MainWindow(shared_ptr<RoomItemWidget> r, shared_ptr<MapWidget> m, shared_ptr<TextBoxWidget> t, InventoryWidget* i){
    this->map = m;
    this-> inv = i;
    this-> room = r;
    this-> text = t;
    //sets parents so they're displayed correctly
    map->setParent(this);
    room->setParent(this);
    text->setParent(this);
    inv->setParent(this);
    setCentralWidget(map.get());
    //boilerplate stuff to set stuff where we want it
    resize(WINDOW_W,WINDOW_H);
    map->setGeometry(MAP_X,MAP_Y-30,MAP_W,MAP_H+30);
    inv->setGeometry(PLAYERINV_X,INV_Y-30,INV_W,INV_H+30);
    inv->rightInventoryList->setGeometry(0,30,INV_W,INV_H);
    inv->rightEquipmentList->setGeometry(0,30,INV_W,INV_H);
    inv->changeInvButton->setGeometry(0,0,30,30);
    inv->inventoryType->setGeometry(INV_W-110,0,110,30);
    inv->playerStats->move(INV_W/2-inv->playerStats->width(),0);
    room->setGeometry(ROOMINV_X,INV_Y-30,INV_W,INV_H+30);
    room->listWidget->setGeometry(0,30,INV_W,INV_H);
    text->setGeometry(TEXTBOX_X,TEXTBOX_Y,TEXTBOX_W,TEXTBOX_H);
    text->textBox->resize(TEXTBOX_W,TEXTBOX_H);
    this->setFixedSize(WINDOW_W,WINDOW_H);
    //this->showFullScreen();
    //this->setWindowFlag(Qt::FramelessWindowHint);
}
