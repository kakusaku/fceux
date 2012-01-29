//Specification file for Greenzone class

//#define LAG_FLAG_BIT 1
#define TIME_BETWEEN_CLEANINGS 10000	// in milliseconds

#define GREENZONE_ID_LEN 10

// greenzone cleaning masks
#define EVERY16TH 0xFFFFFFF0
#define EVERY8TH 0xFFFFFFF8
#define EVERY4TH 0xFFFFFFFC
#define EVERY2ND 0xFFFFFFFE

class GREENZONE
{
public:
	GREENZONE();
	void init();
	void reset();
	void free();
	void update();

	void save(EMUFILE *os, bool really_save = true);
	bool load(EMUFILE *is);

	void TryDumpIncremental(bool lagFlag = true);

	bool loadTasSavestate(int frame);
	void storeTasSavestate(int frame);

	void GreenzoneCleaning();
	void ClearSavestate(int index);

	void InvalidateAndCheck(int after);
	void Invalidate(int after);

	int FindBeginningOfGreenZone(int starting_index = 0);

	// data
	int greenZoneCount;
	std::vector<std::vector<uint8>> savestates;
	std::vector<uint8> lag_history;

private:
	int next_cleaning_time;

};