//
//  poNode.h
//  BasicTest
//
//  Created by Stephen Varga on 3/17/14.
//
//
#pragma once

#include "cinder/Cinder.h"
#include "cinder/CinderMath.h"

#include "poScene.h"

using namespace ci;

namespace po {
    //Forward declare Scene
    class Scene;
    typedef std::shared_ptr<Scene> SceneRef;
    
    class Node;
    typedef std::shared_ptr<Node> NodeRef;
    
    class Node
    : public std::enable_shared_from_this<Node>
    {
    friend class Scene;
    public:
        
        static NodeRef create();
        
        ~Node();
        
        //------------------
        //UPDATE/DRAW
        
        virtual void update();
        virtual void draw();
        
        //------------------
        //SCENE GRAPH
        
        //Scene
        SceneRef getScene();
        
        //Parent
        void setParent(NodeRef node);
        NodeRef getParent() const;
        bool hasParent();
        
        //Children
        int getNumChildren();
        NodeRef addChild(NodeRef node);
        bool removeChild(NodeRef node);
        
        //Dimensions
        float getWidth();
        float getHeight();
        
        //Bounds & Frame
        void setDrawBounds(bool shouldDraw);
        virtual ci::Rectf getBounds();
        
        void setDrawFrame(bool shouldDraw);
        ci::Rectf getFrame();
        
        //------------------
        //ATTRIBUTES
        std::string name;
        Vec2f position;
        Vec3f scale;
        Vec3f rotation;
        
        float alpha;
        ci::Color fillColor;
        ci::Color strokeColor;
        
        bool visible;
        
        //------------------
        //BOUNDS & FRAME
//        ci::Rectf getBounds();
//        void setDrawBounds(bool bDrawBounds);
//        bool getDrawBounds();
//        
//        ci::Rectf getFrame();
//        void setDrawFrame();
//        bool getDrawFrame();
//        
//        int getDrawOrder();
    protected:
        Node();
        
    private:
        //Update and Draw trees, traverse child nodes
        virtual void updateTree();
        virtual void drawTree();
        
        //Scene this node belongs to
        SceneRef scene;
        
        //Bounds and frame
        void drawBounds();
        bool bDrawBounds;
        
        void drawFrame();
        bool bDrawFrame;
        
        //Parent and child nodes
        void removeParent();
        
        std::weak_ptr<Node> parent;
        std::vector<NodeRef> children;
        
        //Unique identifier
        uint uid;
    };
}