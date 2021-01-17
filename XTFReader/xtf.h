/*--------------------------------------------------------------------
 *    side_scan_mosaic:	xtf.h	5/12/2020
 *
 *--------------------------------------------------------------------*/
/*
 * xtf.h contains the data structure of .xtf format.
 * Author:	qiukang
 * Date:	May 12, 2020
 *--------------------------------------------------------------------*/

/* turn on debug statements here */
/* #define XTF_DEBUG 1 */

/* maximum number of beams and pixels */
#ifndef XTF_H_
#define XTF_H_

#define XTF_SS_MAXBEAMS 1
#define XTF_MAXRAWPIXELS 15360
#define XTF_COMMENT_LENGTH 200
#define XTF_MAXLINE 16384
static const unsigned int XTF_FILEHEADERLEN=1024;
static const unsigned int XTF_PINGHEADERLEN=256;
static const unsigned short XTF_MAGIC_NUMBER=0xFACE;
static const unsigned char XTF_DATA_SIDESCAN=0;
static const unsigned char XTF_DATA_ANNOTATION=1;
static const unsigned char XTF_DATA_BATHYMETRY=2;
static const unsigned char XTF_DATA_ATTITUDE=3;
static const unsigned char XTF_DATA_POSITION=100;
static const unsigned char XTF_HEADER_KLEINV4_DATA_PAGE=108;
// #define XTF_HEADER_SONAR 0              // sidescan and subbottom
// #define XTF_HEADER_NOTES 1              // notes - text annotation
// #define XTF_HEADER_BATHY 2              // bathymetry (Seabat, Odom)
// #define XTF_HEADER_ATTITUDE 3           // TSS or MRU attitude (pitch, roll, heave, yaw)
// #define XTF_HEADER_FORWARD 4            // forward-look sonar (polar display)
// #define XTF_HEADER_ELAC 5               // Elac multibeam
// #define XTF_HEADER_RAW_SERIAL 6         // Raw data from serial port
// #define XTF_HEADER_EMBED_HEAD 7         // Embedded header structure
// #define XTF_HEADER_HIDDEN_SONAR 8       // hidden (non-displayable) ping
// #define XTF_HEADER_SEAVIEW_ANGLES 9     // Bathymetry (angles) for Seaview
// #define XTF_HEADER_SEAVIEW_DEPTHS 10    // Bathymetry from Seaview data (depths)
// #define XTF_HEADER_HIGHSPEED_SENSOR 11  // used by Klein (Cliff Chase) 0=roll, 1=yaw
// #define XTF_HEADER_ECHOSTRENGTH 12      // Elac EchoStrength (10 values)
// #define XTF_HEADER_GEOREC 13            // Used to store mosaic params
// #define XTF_HEADER_K5000_BATHYMETRY 14  // Bathymetry data from the Klein 5000
// #define XTF_HEADER_HIGHSPEED_SENSOR2 15 // High speed sensor from Klein 5000
// #define XTF_HEADER_RAW_CUSTOM 199       // Raw Custom Header

#pragma pack(1)
struct xtf_chaninfo {
    char TypeOfChannel;
    char SubChannelNumber;
    unsigned short CorrectionFlags;
    unsigned short UniPolar;
    unsigned short BytesPerSample;
    unsigned int SamplesPerChannel;
    char ChannelName[16];
    float VoltScale;      /* maximum value (V) */
    float Frequency;      /* Hz */
    float HorizBeamAngle; /* degrees */
    float TiltAngle;
    float BeamWidth;
    float OffsetX;
    float OffsetY;
    float OffsetZ;
    float OffsetYaw;
    float OffsetPitch;
    float OffsetRoll;
    //unsigned short BeamsPerArray; /*For forward look only(i.e., Sonatech DDS)*/
    //unsigned char SampleFormat; /* 0=Legacy 1=4-byte IBM float 2=4-byte integer........*/
    char ReservedArea[56];
};

struct xtf_fileheader {
    char FileFormat; /* Set to 123 (0x7B */
    char SystemType; /* Set to 1 */
    char RecordingProgramName[8];
    char RecordingProgramVersion[8];
    char SonarName[16];
    unsigned short SonarType; /* 	0 = Reserved
                      1 = JAMSTEC
                      2 = Analog_c31
                      3 = SIS1000
                      4 = Analog_32chan
                      5 = Klein2000
                      6 = RWS
                      7 = DF1000
                      8 = SeaBat 9001
                      9 = Klein595
                      10 = EGG260
                      11 = Sonatech_DDS
                      12 = Echoscan
                      13 = Elac Bottomchart 1180
                      14 = Klein 5000
                      15 = Reson SeaBat 8101
                      16 = Imagenex model 858
                      17 = USN SILOS with 3-channel analog
                      18 = Sonatech super high res sidescan sonar
                      19 = Delph AU32 Analog input (2 channel)
                      20 = Generic sonar using the memory-mapped
                          file interface
                      21 = Simrad SM2000
                      22 = Standard multibedia audio
                      23 = Edgetech ACI card for 260 sonar throug PC31 card
                      24 = Edgetech black box
                      25 = Fugro deeptow
                      26 = C&C Edgetech chirp conversion program
                      27 = DTI SAS synthetic aperture processor (mmap file)
                      */
    char NoteString[64];
    char ThisFileName[64];
    unsigned short NavUnits;              /* 0 = meters, 3 = degrees */
    unsigned short NumberOfSonarChannels; /* if <= 6 use 1024 byte header,
                          if > 6 use 2048 byte header */
    unsigned short NumberOfBathymetryChannels;
    unsigned short Reserved1;
    unsigned short Reserved2;
    unsigned short Reserved3;
    unsigned short Reserved4;
    unsigned short Reserved5;
    unsigned short Reserved6;
    char ProjectionType[12]; /* not currently used */
    char SpheroidType[10];   /* not currently used */
    int NavigationLatency;   /* GPS_time_received - GPS_time_sent (msec) */
    float OriginY;           /* not currently used */
    float OriginX;           /* not currently used */
    float NavOffsetY;        /* Multibeam nav offset (m) */
    float NavOffsetX;        /* Multibeam nav offset (m) */
    float NavOffsetZ;        /* Multibeam nav z offset (m) */
    float NavOffsetYaw;      /* Multibeam heading offset (m) */
    float MRUOffsetY;        /* Multibeam MRU y offset (m) */
    float MRUOffsetX;        /* Multibeam MRU x offset (m) */
    float MRUOffsetZ;        /* Multibeam MRU z offset (m) */
    float MRUOffsetYaw;      /* Multibeam MRU heading offset (m) */
    float MRUOffsetPitch;    /* Multibeam MRU pitch offset (degrees) */
    float MRUOffsetRoll;     /* Multibeam MRU roll offset (degrees) */
    struct xtf_chaninfo chaninfo[6];
};

struct xtf_packetheader {
    unsigned short MagicNumber;        /* 0xFACE */
    unsigned char HeaderType;            /* 0 = sonar ping, 1 = annotation, 2 = bathymetry, 3 = attitude */
    unsigned char SubChannelNumber;      /* which multibeam head */
    unsigned short NumChansToFollow; /* Number of beams to follow */
    unsigned short Reserved1[2];
    unsigned int NumBytesThisRecord; /* total byte count including this header */
};

struct xtf_attitudeheader {
    struct xtf_packetheader packetHeader;
    unsigned int Reserved2[4];
    float Pitch;
    float Roll;
    float Heave;
    float Yaw;
    unsigned int TimeTag; /* time tag (msec) */
    float Heading;
    char Reserved3[10];
};

struct xtf_pingheader {
    struct xtf_packetheader packetHeader;
    unsigned short Year;
    unsigned char Month;
    unsigned char Day;
    unsigned char Hour;
    unsigned char Minute;
    unsigned char Second;
    unsigned char HSeconds;
    unsigned short JulianDay;
    unsigned short CurrentLineID;
    unsigned short EventNumber;
    unsigned int PingNumber;
    float SoundVelocity; /* Half sound speed (e.g. 750 m/sec instead of 1500 m/sec) */
    float OceanTide;     /* (m) */
    unsigned int Reserved2;
    float ConductivityFreq;      /* Raw CTD conductivity frequency (Hz) */
    float TemperatureFreq;       /* Raw CTD temperature frequency (Hz) */
    float PressureFreq;          /* Raw CTD pressure frequency (Hz) */
    float PressureTemp;          /* Raw CTD pressure temperature (deg C) */
    float Conductivity;          /* computed CTD conductivity (siemens/m) */
    float WaterTemperature;      /* computed CTD temperature (deg C) */
    float Pressure;              /* computed CTD water pressure (psia) */
    float ComputedSoundVelocity; /* water sound velocity (m/sec) */
    float MagX;                  /* X-axis magnetometer (mGauss) */
    float MagY;                  /* Y-axis magnetometer (mGauss) */
    float MagZ;                  /* Z-axis magnetometer (mGauss) */
    float AuxVal1;
    float AuxVal2;
    float AuxVal3;
    float AuxVal4;
    float AuxVal5;
    float AuxVal6;
    float SpeedLog;          /* towfish speed (kts) */
    float Turbidity;         /* turbity (0-5V * 10000) */
    float ShipSpeed;         /* ship speed (kts) */
    float ShipGyro;          /* ship heading (deg) */
    double ShipYcoordinate;  /* ship latitude or northing */
    double ShipXcoordinate;  /* ship longitude or easting */
    short ShipAltitude;      /* ship altitude (decimeters) */
    short ShipDepth;         /* ship depth (decimeters) */
    unsigned char FixTimeHour;   /* last nav fix time (hour) */
    unsigned char FixTimeMinute; /* last nav fix time (min) */
    unsigned char FixTimeSecond; /* last nav fix time (sec) */
    char FixTimeHSecond;
    float SensorSpeed;        /* towfish speed (kts) */
    float KP;                 /* kilometers pipe (km) */
    double SensorYcoordinate; /* towfish latitude or northing */
    double SensorXcoordinate; /* towfish longitude or easting */
    short SonarStatus;			/*towfish cable information. System status value, sonar dependant(displayed in Status window).*/
    short RangeToFish;         /* slant range to towfish * 10 */
    short BearingToFish;       /* bearing to towfish * 100 */
    short CableOut;              /* cable out (m) */
    float Layback;               /* distance from ship to sensor (m) */
    float CableTension;          /* cable tension */
    float SensorDepth;           /* towfish depth (m) */
    float SensorPrimaryAltitude; /* towfish altitude (m) */
    float SensorAuxAltitude;     /* towfish altitude (m) */
    float SensorPitch;           /* sensor pitch (deg) */
    float SensorRoll;            /* sensor roll (deg) */
    float SensorHeading;         /* sensor heading (deg) */
    float Heave;                 /* sensor heave (m) */
    float Yaw;                   /* sensor yaw (deg) */
    int AttitudeTimeTag;         /* time tag from MRU */
    float DOT;                   /* distance off track */
    char ReservedSpace[24];
};

struct xtf_pingchanheader {
    unsigned short ChannelNumber;    /* Typically,  */
                                     /* 0=port (low frequency) */
                                     /* 1=stbd (low frequency) */
                                     /* 2=port (high frequency) */
                                     /* 3=stbd (high frequency) */
    unsigned short DownsampleMethod; /* 2=MAX, 4=RMS */
    float SlantRange;                /* Slant range of the data in meters */
    float GroundRange;               /* Ground range of the data in meters */
                                     /*   (SlantRange^2 - Altitude^2) */
    float TimeDelay;                 /* Amount of time (in seconds) to the start of recorded data */
                                     /*   almost always 0.0 */
    float TimeDuration;              /* Amount of time (in seconds) recorded */
    float SecondsPerPing;            /* Amount of time (in seconds) from ping to ping */

    unsigned short ProcessingFlags; /* 4=TVG, 8=BAC&GAC, 16=Filter, etc... */
                                    /*   almost always 0 */
    unsigned short Frequency;       /* Center transmit frequency for this channel. */
                                    /*   when non-zero, replaces value found in file */
                                    /*   header CHANINFO struct ChanInfo->SamplesPerChannel. */
                                    /*   This allows samples per channel to change on the fly. */

    unsigned short InitialGainCode; /* Settings as transmitted by sonar */
    unsigned short GainCode;
    unsigned short BandWidth;

    /* Contact information - updated when contacts are saved through Target.exe */
    unsigned int ContactNumber;
    unsigned short ContactClassification;
    unsigned char ContactSubNumber;
    unsigned char ContactType;

    unsigned int NumSamples; /* Number of samples that will follow this structure.  The */
                             /* number of bytes will be this value multipied by the */
                             /* number of bytes per sample (given in the file header) */

    unsigned short Reserved;   /* Obsolete. */
    float ContactTimeOffTrack; /* Time off track to this contact (stored in milliseconds) */
    unsigned char ContactCloseNumber;
    unsigned char Reserved2;

    float FixedVSOP; /* Fixed along-track size of each ping, stored in cm. */
                     /*  on multibeam system with zero beam spread, this value */
                     /*  needs to be filled in to prevent Isis from calculating */
                     /*  along-track ground coverage based on beam spread and  */
                     /*  speed over ground.  In order for */
                     /* Target to use this number, "223" */
                     /* or later must be set in */
                     /* XTFFILEHEADER.RecordingProgramVersion */

    unsigned char ReservedSpace[6]; /* reserved for future expansion */
};

struct xtf_notesheader {
    struct xtf_packetheader packetheader;
    //
    // Date and time of the annotation
    //
    unsigned short Year;
    unsigned char Month;
    unsigned char Day;
    unsigned char Hour;
    unsigned char Minute;
    unsigned char Second;
    unsigned char HSeconds;

    char NotesText[256 - 56];
};

struct xtf_rawcustomheader {
    unsigned char MagicNumber[2]; /* 0xFACE */
    unsigned char HeaderType;     /* 199 = XTFRAWCUSTOMHEADER*/
    unsigned char ManufacturerID; /* 1 = Benthos */
    unsigned short SonarID;   /* 1624 = 1624	*/
    unsigned short PacketID;  /* TBD */
    unsigned short Reserved1[1];
    unsigned int NumBytesThisRecord; // Total byte count for this update

    unsigned short Year;
    unsigned char Month;
    unsigned char Day;
    unsigned char Hour;
    unsigned char Minute;
    unsigned char Second;
    unsigned char HSeconds;

    unsigned short JulianDay;
    unsigned short Reserved2[2];
    unsigned int PingNumber;
    unsigned int TimeTag;
    unsigned int NumCustomerBytes;
    unsigned char Reserved3[24]; // Padding to make the structure 64 bytes
};
#pragma pack()

struct xtf_pingpacket{
    struct xtf_pingheader pingHeader;
    struct xtf_pingchanheader pingChanHeader[2];
    void * p_ping[2];
};
struct xtf_bathmetrypacket{
    struct xtf_pingheader bathmetryHeader;
    void * p_bathmetry;
};

struct xtffile_struct {
    /* type of data record */
    int kind; /* Data vs Comment */

    /* type of sonar */
    int sonar; /* Type of Benthos sonar */

    /* xtf file header */
    struct xtf_fileheader fileheader;

    /* xtf attitude record */
    struct xtf_attitudeheader attitudeheader;

    /* xtf raw custom record */
    struct xtf_rawcustomheader rawcustomheader;

    /* xtf Benthos sidescan ping record */
    struct xtf_pingheader pingheader;
    struct xtf_pingchanheader pingchanportheader;
    unsigned short ssrawport[XTF_MAXRAWPIXELS];
    struct xtf_pingchanheader pingchanstbdheader;
    unsigned short ssrawstbd[XTF_MAXRAWPIXELS];

    /* comment */
    char comment[XTF_COMMENT_LENGTH];
};

#endif
