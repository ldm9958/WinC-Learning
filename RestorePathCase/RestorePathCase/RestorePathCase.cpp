// RestorePathCase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string>

using namespace std;

//�ָ��ļ�·���Ĵ�Сд
std::wstring GetActualPathName( const wchar_t* path )
{
	const wchar_t kSeparator = L'\\';

	size_t length = wcslen(path);
	wchar_t buffer[MAX_PATH];
	memcpy( buffer, path, (length+1) * sizeof(path[0]) );

	size_t i = 0;

	std::wstring result;

	//�ж��Ƿ�����·��
	if( length >= 2 && buffer[0] == kSeparator && buffer[1] == kSeparator )
	{
		int skippedCount = 0;
		i = 2;
		while( i < length && skippedCount < 2 )
		{
			if( buffer[i] == kSeparator )
				++skippedCount;
			++i;
		}

		result.append( buffer, i );
	}
	//�̷�Ĭ�ϴ�д
	else if( length >= 2 && buffer[1] == L':' )
	{
		result += towupper(buffer[0]);
		result += L':';
		if( length >= 3 && buffer[2] == kSeparator )
		{
			result += kSeparator;
			i = 3; 
		}
		else
		{
			i = 2;
		}
	}

	size_t lastComponentStart = i;
	bool addSeparator = false;

	while( i < length )
	{
		//����'\\'
		while( i < length && buffer[i] != kSeparator )
			++i;

		if( addSeparator )
			result += kSeparator;

		bool foundSeparator = (i < length);
		buffer[i] = 0;
		SHFILEINFOW info;

		info.szDisplayName[0] = 0;
		if( SHGetFileInfoW( buffer, 0, &info, sizeof(info), SHGFI_DISPLAYNAME ) )
		{
			result += info.szDisplayName;
		}
		else
		{
			//�ļ�������
			result.append( buffer + lastComponentStart, i - lastComponentStart );
		}

		if( foundSeparator )
			buffer[i] = kSeparator;

		++i;
		lastComponentStart = i;
		addSeparator = true;
	}

	return result;
}
  
int _tmain(int argc, _TCHAR* argv[])
{
	wstring strTemp = L"E:\\git-repo\\MyWindowsC++Learning\\�½��ļ���dasd21d����\\�½��ı��ĵ�.txt";
	wstring strReal = L"";
	strReal = GetActualPathName(strTemp.c_str());
	wprintf(L"strReal=%s",strReal.c_str());
	system("pause");
	return 0;
}

