#include "ray_audio_device.h"

#if defined(WIN32)

namespace ray {
namespace devices {

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

} // devices
} // ray


#endif // _WIN32
