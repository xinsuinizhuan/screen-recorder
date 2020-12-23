#pragma once

#include "base\ray_macro.h"

#include "include\iray_audio_device.h"
#include "include\ray_refptr_object.h"


namespace ray {
namespace devices {

using namespace recorder;

class AudioDeviceCollection :public IAudioDeviceCollection {

private:
	AudioDeviceCollection();
	
	~AudioDeviceCollection();

	DISALLOW_COPY_AND_ASSIGN(AudioDeviceCollection);
	FRIEND_CLASS_REFCOUNTEDOBJECT(AudioDeviceCollection);

	friend class AudioDeviceManager;

public:

	int getDeviceCount() override;

	virtual AudioDeviceInfo getDeviceInfo(int index) override;
	
};

class AudioDeviceManager : public IAudioDeviceManager {

private:
	AudioDeviceManager();
	~AudioDeviceManager();

	DISALLOW_COPY_AND_ASSIGN(AudioDeviceManager);
	FRIEND_CLASS_REFCOUNTEDOBJECT(AudioDeviceManager);

public:

	void registerObserver(IAudioDeviceObserver* observer) override;

	void unregisterObserver(const IAudioDeviceObserver* observer) override;

	int setMicrophone(const char id[kAdmDeviceIdSize]) override;

	int setMicrophoneVolume(const unsigned int volume) override;

	int getMicrophoneVolume(unsigned int& volume) override;

	ray_refptr<IAudioDeviceCollection> getMicrophoneCollection() override;

	int setSpeaker(const char id[kAdmDeviceIdSize]) override;

	int setSpeakerVolume(const unsigned int volume) override;

	int getSpeakerVolume(unsigned int& volume) override;

	ray_refptr<IAudioDeviceCollection> getSpeakerCollection() override;

private:

};

}
}