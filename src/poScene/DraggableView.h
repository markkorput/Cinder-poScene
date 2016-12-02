#pragma once

#include "poScene/View.h"

#include "cinder/Signals.h"

namespace po { namespace scene {
	typedef std::shared_ptr<class DraggableView> DraggableViewRef;

	class DraggableView : public po::scene::View {
	public:
		typedef ci::signals::Signal<void(DraggableViewRef&)> DragAndDropSignal;

		static DraggableViewRef create();
		static DraggableViewRef create(ci::vec2 snapBackPosition);

		void setup() override;

		virtual void connectEvents();
		virtual void snapBackToPosition() { setPosition(mSnapPosition); };

		void setSnapBackPosition(ci::vec2 snapBackPosition) { mSnapPosition = snapBackPosition; }
		ci::vec2 getSnapBackPosition() { return mSnapPosition; }

		void setSnapsBackToPosition(bool snapsBackToPosition) { mSnapsBack = snapsBackToPosition; }
		bool getSnapsBackToPosition() { return mSnapsBack; }

		DragAndDropSignal &getSignalDragBegan()		{ return mSignalDragBegan; };
		DragAndDropSignal &getSignalDragged()		{ return mSignalDragged; };
		DragAndDropSignal &getSignalDragEnded()		{ return mSignalDragEnded; };

	protected:
		DraggableView();
		DraggableView(ci::vec2 snapBackPosition);

		bool mIsDragging;
		ci::vec2 mDragOffset;

		static const int DRAGGING_EVENT_ID_NONE = -1;
		int mDraggingEventID;

		// Signals
		DragAndDropSignal mSignalDragBegan, mSignalDragged, mSignalDragEnded;

	private:

		void mouseEventHandler(po::scene::MouseEvent &event);
		void touchEventHandler(po::scene::TouchEvent &event);

		bool mSnapsBack;
		ci::vec2 mSnapPosition;
	};
}}