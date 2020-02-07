#pragma once

#include <array>

#include "openvr.h"
#include "ofLog.h"
#include "ofVectorMath.h"
#include "ofTexture.h"
#include "ofPixels.h"

namespace ofxOpenVrUtil {
	class TrackedCamera {
	public:
		TrackedCamera();
		~TrackedCamera();

		void setup(vr::IVRSystem* vrSys);
		bool open();
		bool close();

		bool start();
		bool stop();

		bool isOpen() const { return bOpen; }
		bool isStreaming() const { return bStreaming; }

		void update();

		const ofTexture getTexture(vr::Hmd_Eye eye) const {
			return tex[eye];
		}

	private:
		vr::IVRSystem* vrSys;
		vr::IVRCompositor* vrComp;
		vr::IVRTrackedCamera* trackedCamera;
		vr::TrackedCameraHandle_t trackedCameraHandle;
		
		uint32_t frameWidth, frameHeight;
		uint32_t bufferSize;
		std::vector<uint8_t> rawFrameBuffer;
		std::array<ofTexture, 2> tex;
		std::array<ofPixels, 2> pix;
		uint32_t lastFrameCount;

		bool bOpen;
		bool bStreaming;
	};
}
