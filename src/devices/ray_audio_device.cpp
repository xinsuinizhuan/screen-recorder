#include "ray_audio_device.h"

namespace ray {
namespace devices {

AudioDeviceCollection::AudioDeviceCollection()
{
}

AudioDeviceCollection::~AudioDeviceCollection()
{
}

int AudioDeviceCollection::getDeviceCount()
{
	return 0;
}

AudioDeviceInfo AudioDeviceCollection::getDeviceInfo(int index)
{
	return AudioDeviceInfo();
}



AudioDeviceManager::AudioDeviceManager()
{
}

AudioDeviceManager::~AudioDeviceManager()
{
}

void AudioDeviceManager::registerObserver(IAudioDeviceObserver * observer)
{
}

void AudioDeviceManager::unregisterObserver(const IAudioDeviceObserver * observer)
{
}

int AudioDeviceManager::setMicrophone(const char id[kAdmDeviceIdSize])
{
	return 0;
}

int AudioDeviceManager::setMicrophoneVolume(const unsigned int volume)
{
	return 0;
}

int AudioDeviceManager::getMicrophoneVolume(unsigned int & volume)
{
	return 0;
}

ray_refptr<IAudioDeviceCollection> AudioDeviceManager::getMicrophoneCollection()
{
	return nullptr;
}

int AudioDeviceManager::setSpeaker(const char id[kAdmDeviceIdSize])
{
	return 0;
}

int AudioDeviceManager::setSpeakerVolume(const unsigned int volume)
{
	return 0;
}

int AudioDeviceManager::getSpeakerVolume(unsigned int & volume)
{
	return 0;
}

ray_refptr<IAudioDeviceCollection> AudioDeviceManager::getSpeakerCollection()
{
	return nullptr;
}

}
}

