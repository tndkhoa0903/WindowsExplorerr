#ifndef CDRIVE_H
#define CDRIVE_H

#include <windows.h>
#include <tchar.h>
#include "DriveSize.h"

#define MAX_BUFFER_LEN 105
#define MAX_TYPE_LEN	106
//Define for GetVolumeInformation
#define VOLUME_NAME_SIZE		MAX_BUFFER_LEN
#define VOLUME_SERIAL_NUMBER	NULL
#define MAX_COMPONENT_LEN		NULL
#define FILE_SYSTEM_FLAG		NULL
#define FILE_SYSTEM_NAME_BUFF	NULL //Name of File System (NTFS, FAT,...)
#define FILE_SYSTEM_NAME_SIZE	0  //Size of buffer for file system name

//For allocate memory#define MAX_TYPE_LEN		20
#define MAX_DRIVE_LETTER	4
#define MAX_VOLUME_NAME		30
#define MAX_DISPLAY_NAME	30


#define FIXED_DRIVE		_T("Local Disk")
#define REMOVABLE_DRIVE _T("Removable Drive")
#define CD_ROM			_T("CD-ROM")
#define REMOTE_DRIVE	_T("Network Drive")

class DriveHelper
{
private:
	TCHAR** mDriveLetter;
	TCHAR** mVolumeLabel;
	TCHAR** mDriveType;
	int mNumberOfDrive;
	CDriveSize** mDriveSize;

	CDriveSize* getDriveSize(int i);

public:
	DriveHelper();
	~DriveHelper();

	TCHAR* getDriveLetter(const int &i);
	TCHAR* getDisplayName(const int &i);
	int getCount();


	void getSystemDrives();

	TCHAR* getDriveType(int position);
	LPWSTR getTotalSize(int i);
	LPWSTR getFreeSpace(int i);
};

#endif