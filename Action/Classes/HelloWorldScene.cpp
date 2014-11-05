#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    
    Size size = Director::getInstance()->getVisibleSize();
    log("%f,%f",size.width,size.height);
    auto label = Label::createWithSystemFont("Clike To Move", "Courier", 30);
    label ->setPosition(size.width/2, size.height/2);
    addChild(label);
    
   
    
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener ->onTouchBegan = [label](Touch *t,Event *e){
        if (label ->cocos2d::Node::getBoundingBox().containsPoint(t->getLocation())) {
            //移动
//            label ->runAction(MoveTo::create(1.0, Point(100,100)));
           
            //移动
//            label ->runAction(MoveBy::create(1.0, Point(-10,-10)));
           
            //反转
//            label ->runAction(MoveBy::create(1.0, Point(-10,-10))->reverse());
           
            //混合动作 同时进行
//            label ->runAction(Spawn::create(MoveBy::create(1, Point(100,100)),RotateBy::create(1, 360),Blink::create(1, 5), NULL));
            
            
            //动作序列 按顺序执行
//            label ->runAction(Sequence::create(MoveTo::create(1, Point(100,100)),RotateBy::create(1, 360),Blink::create(1, 5), NULL));
            
            
            //动作监听
             label ->runAction(Sequence::create(
                                                MoveTo::create(1, Point(100,100)),
                                                RotateBy::create(1, 360),     Blink::create(1, 5),
                                                CallFunc::create([](){
                 MessageBox("complete!", "Mission Complete");
             }), NULL));
            
            
        }
        
       
        
        return false;
    };
    
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, label);
  
    //旋转 -1为持续旋转类似forever
//    label ->runAction(Repeat::create(RotateBy::create(0.1, 180), -1));
  
    //永久旋转
//    label ->runAction(RepeatForever::create(RotateBy::create(1, 180)));
    
    //闪烁
//    label ->runAction(Blink::create(5, 20));
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
