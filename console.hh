#pragma once

class qConsole
{
public:
	int mArgc;
	char** mArgv;

	qConsole(int argc, char** argv) : mArgc(argc), mArgv(argv) {}

	int GetArgIndex(const char* arg)
	{
		for (int i = 0; mArgc > i; ++i)
		{
			if (UFG::qStringCompareInsensitive(mArgv[i], arg)) {
				continue;
			}

			return i;
		}

		return -1;
	}

	bool HasArg(const char* arg) { return (GetArgIndex(arg) != -1); }

	UFG::qString GetArgument(const char* arg)
	{
		int idx = GetArgIndex(arg) + 1;
		if (idx == 0 || idx >= mArgc) {
			return {};
		}

		return mArgv[idx];
	}
};