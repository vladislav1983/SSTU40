//==========================================================================================================
//  Used with pic30-gcc. and dsPIC.
//  Language tool versions: pic30-as.exe v3.30, pic30-gcc.exe v3.30, pic30-ld.exe v3.30, pic30-ar.exe v3.30
//==========================================================================================================
//    File name   : mathtools.c
//    Description : mathematical tools
//    V.Gyurov
// +----------+-------------+--------------------------------------------------------+
// |Date      | Version     | Description                                            |
// +----------+-------------+--------------------------------------------------------+
//  28.06.2011  V1.0            Initial release
//
//
//==========================================================================================================

//==========================================================================================================
// Body Identification  
//==========================================================================================================
#ifdef __MATHTOOLS_C
#error "!!! FileName ID. It should be Unique !!!"
#else
#define __MATHTOOLS_C
#endif

//==========================================================================================================
// Included files to resolve specific definitions in this file
//==========================================================================================================
#include "MathTools.h"


//==========================================================================================================
// Local constants
//==========================================================================================================
const S16	sintab[SINTAB_LEN] = {
0,402,804,1206,1607,2009,2410,2811,3211,3611,4011,4409,4807,5205,5601,5997,
6392,6786,7179,7571,7961,8351,8739,9126,9511,9895,10278,10659,11038,11416,11792,12166,
12539,12909,13278,13645,14009,14372,14732,15090,15446,15799,16150,16499,16845,17189,17530,17868,
18204,18537,18867,19194,19519,19840,20159,20474,20787,21096,21402,21705,22004,22301,22594,22883,
23169,23452,23731,24006,24278,24546,24811,25072,25329,25582,25831,26077,26318,26556,26789,27019,
27244,27466,27683,27896,28105,28309,28510,28706,28897,29085,29268,29446,29621,29790,29955,30116,
30272,30424,30571,30713,30851,30984,31113,31236,31356,31470,31580,31684,31785,31880,31970,32056,
32137,32213,32284,32350,32412,32468,32520,32567,32609,32646,32678,32705,32727,32744,32757,32764,
32766,32764,32757,32744,32727,32705,32678,32646,32609,32567,32520,32468,32412,32350,32284,32213,
32137,32056,31970,31880,31785,31684,31580,31470,31356,31236,31113,30984,30851,30713,30571,30424,
30272,30116,29955,29790,29621,29446,29268,29085,28897,28706,28510,28309,28105,27896,27683,27466,
27244,27019,26789,26556,26318,26077,25831,25582,25329,25072,24811,24546,24278,24006,23731,23452,
23169,22883,22594,22301,22004,21705,21402,21096,20787,20474,20159,19840,19519,19194,18867,18537,
18204,17868,17530,17189,16845,16499,16150,15799,15446,15090,14732,14372,14009,13645,13278,12909,
12539,12166,11792,11416,11038,10659,10278,9895,9511,9126,8739,8351,7961,7571,7179,6786,
6392,5997,5601,5205,4807,4409,4011,3611,3211,2811,2410,2009,1607,1206,804,402,
0,-402,-804,-1206,-1607,-2009,-2410,-2811,-3211,-3611,-4011,-4409,-4807,-5205,-5601,-5997,
-6392,-6786,-7179,-7571,-7961,-8351,-8739,-9126,-9511,-9895,-10278,-10659,-11038,-11416,-11792,-12166,
-12539,-12909,-13278,-13645,-14009,-14372,-14732,-15090,-15446,-15799,-16150,-16499,-16845,-17189,-17530,-17868,
-18204,-18537,-18867,-19194,-19519,-19840,-20159,-20474,-20787,-21096,-21402,-21705,-22004,-22301,-22594,-22883,
-23169,-23452,-23731,-24006,-24278,-24546,-24811,-25072,-25329,-25582,-25831,-26077,-26318,-26556,-26789,-27019,
-27244,-27466,-27683,-27896,-28105,-28309,-28510,-28706,-28897,-29085,-29268,-29446,-29621,-29790,-29955,-30116,
-30272,-30424,-30571,-30713,-30851,-30984,-31113,-31236,-31356,-31470,-31580,-31684,-31785,-31880,-31970,-32056,
-32137,-32213,-32284,-32350,-32412,-32468,-32520,-32567,-32609,-32646,-32678,-32705,-32727,-32744,-32757,-32764,
-32766,-32764,-32757,-32744,-32727,-32705,-32678,-32646,-32609,-32567,-32520,-32468,-32412,-32350,-32284,-32213,
-32137,-32056,-31970,-31880,-31785,-31684,-31580,-31470,-31356,-31236,-31113,-30984,-30851,-30713,-30571,-30424,
-30272,-30116,-29955,-29790,-29621,-29446,-29268,-29085,-28897,-28706,-28510,-28309,-28105,-27896,-27683,-27466,
-27244,-27019,-26789,-26556,-26318,-26077,-25831,-25582,-25329,-25072,-24811,-24546,-24278,-24006,-23731,-23452,
-23169,-22883,-22594,-22301,-22004,-21705,-21402,-21096,-20787,-20474,-20159,-19840,-19519,-19194,-18867,-18537,
-18204,-17868,-17530,-17189,-16845,-16499,-16150,-15799,-15446,-15090,-14732,-14372,-14009,-13645,-13278,-12909,
-12539,-12166,-11792,-11416,-11038,-10659,-10278,-9895,-9511,-9126,-8739,-8351,-7961,-7571,-7179,-6786,
-6392,-5997,-5601,-5205,-4807,-4409,-4011,-3611,-3211,-2811,-2410,-2009,-1607,-1206,-804,-402
};


/******************************************************************************/
/*
 * SQRT TABLE OF INTEGER      
 * SQRT_TAB[x] = SQRT(x)*32768  0<= x <= 0.25 <->  0<= x <= 8192
*/
/******************************************************************************/
const S16 SQRT_TAB[SQRT_TAB_LEN] = {
0,724,1024,1254,1448,1619,1773,1915,2048,2172,2289,2401,2508,2610,2709,2804,
2896,2985,3072,3156,3238,3318,3396,3472,3547,3620,3692,3762,3831,3899,3965,4031,
4096,4159,4222,4283,4344,4404,4463,4521,4579,4636,4692,4748,4802,4857,4910,4964,
5016,5068,5120,5170,5221,5271,5320,5369,5418,5466,5514,5561,5608,5655,5701,5747,
5792,5837,5882,5926,5970,6014,6058,6101,6144,6186,6228,6270,6312,6353,6394,6435,
6476,6516,6556,6596,6636,6675,6714,6753,6792,6830,6869,6907,6945,6982,7020,7057,
7094,7131,7168,7204,7240,7276,7312,7348,7384,7419,7454,7489,7524,7559,7594,7628,
7662,7697,7731,7764,7798,7832,7865,7898,7931,7964,7997,8030,8062,8095,8127,8159,
8192,8223,8255,8287,8319,8350,8381,8413,8444,8475,8505,8536,8567,8597,8628,8658,
8688,8719,8749,8778,8808,8838,8868,8897,8927,8956,8985,9014,9043,9072,9101,9130,
9158,9187,9216,9244,9272,9300,9329,9357,9385,9413,9440,9468,9496,9523,9551,9578,
9605,9633,9660,9687,9714,9741,9768,9795,9821,9848,9875,9901,9928,9954,9980,10006,
10033,10059,10085,10111,10137,10162,10188,10214,10240,10265,10291,10316,10341,10367,10392,10417,
10442,10467,10492,10517,10542,10567,10592,10617,10641,10666,10690,10715,10739,10764,10788,10812,
10836,10861,10885,10909,10933,10957,10981,11005,11028,11052,11076,11099,11123,11147,11170,11193,
11217,11240,11264,11287,11310,11333,11356,11379,11402,11425,11448,11471,11494,11517,11539,11562,
11585,11607,11630,11652,11675,11697,11720,11742,11764,11787,11809,11831,11853,11875,11897,11919,
11941,11963,11985,12007,12029,12051,12072,12094,12116,12137,12159,12180,12202,12223,12245,12266,
12288,12309,12330,12351,12373,12394,12415,12436,12457,12478,12499,12520,12541,12562,12583,12603,
12624,12645,12666,12686,12707,12728,12748,12769,12789,12810,12830,12851,12871,12891,12912,12932,
12952,12972,12993,13013,13033,13053,13073,13093,13113,13133,13153,13173,13193,13213,13232,13252,
13272,13292,13312,13331,13351,13370,13390,13410,13429,13449,13468,13488,13507,13526,13546,13565,
13584,13604,13623,13642,13661,13681,13700,13719,13738,13757,13776,13795,13814,13833,13852,13871,
13890,13909,13927,13946,13965,13984,14002,14021,14040,14059,14077,14096,14114,14133,14151,14170,
14188,14207,14225,14244,14262,14281,14299,14317,14336,14354,14372,14390,14408,14427,14445,14463,
14481,14499,14517,14535,14553,14571,14589,14607,14625,14643,14661,14679,14697,14714,14732,14750,
14768,14786,14803,14821,14839,14856,14874,14892,14909,14927,14944,14962,14979,14997,15014,15032,
15049,15067,15084,15101,15119,15136,15153,15171,15188,15205,15222,15240,15257,15274,15291,15308,
15325,15342,15360,15377,15394,15411,15428,15445,15462,15479,15495,15512,15529,15546,15563,15580,
15597,15613,15630,15647,15664,15680,15697,15714,15730,15747,15764,15780,15797,15814,15830,15847,
15863,15880,15896,15913,15929,15946,15962,15978,15995,16011,16028,16044,16060,16077,16093,16109,
16125,16142,16158,16174,16190,16207,16223,16239,16255,16271,16287,16303,16319,16335,16351,16367
};

/******************************************************************************/
/*
 * SQRT TABLE OF INTEGER      
 * SQRT_TAB[x] = SQRT(x)*32768  0.25<= x <= 1 <->  0<= x <= 32768
*/
/******************************************************************************/
const S16 SQRT_TAB2[SQRT_TAB_LEN] = {
0,1448,2048,2508,2896,3238,3547,3831,4096,4344,4579,4802,5016,5221,5418,5608,
5792,5970,6144,6312,6476,6636,6792,6945,7094,7240,7384,7524,7662,7798,7931,8062,
8192,8319,8444,8567,8688,8808,8927,9043,9158,9272,9385,9496,9605,9714,9821,9928,
10033,10137,10240,10341,10442,10542,10641,10739,10836,10933,11028,11123,11217,11310,11402,11494,
11585,11675,11764,11853,11941,12029,12116,12202,12288,12373,12457,12541,12624,12707,12789,12871,
12952,13033,13113,13193,13272,13351,13429,13507,13584,13661,13738,13814,13890,13965,14040,14114,
14188,14262,14336,14408,14481,14553,14625,14697,14768,14839,14909,14979,15049,15119,15188,15257,
15325,15394,15462,15529,15597,15664,15730,15797,15863,15929,15995,16060,16125,16190,16255,16319,
16384,16447,16511,16574,16638,16700,16763,16826,16888,16950,17011,17073,17134,17195,17256,17317,
17377,17438,17498,17557,17617,17676,17736,17795,17854,17912,17971,18029,18087,18145,18203,18260,
18317,18375,18432,18488,18545,18601,18658,18714,18770,18826,18881,18937,18992,19047,19102,19157,
19211,19266,19320,19374,19429,19482,19536,19590,19643,19697,19750,19803,19856,19908,19961,20013,
20066,20118,20170,20222,20274,20325,20377,20428,20480,20531,20582,20633,20683,20734,20784,20835,
20885,20935,20985,21035,21085,21135,21184,21234,21283,21332,21381,21430,21479,21528,21577,21625,
21673,21722,21770,21818,21866,21914,21962,22010,22057,22105,22152,22199,22246,22294,22341,22387,
22434,22481,22528,22574,22620,22667,22713,22759,22805,22851,22897,22943,22988,23034,23079,23125,
23170,23215,23260,23305,23350,23395,23440,23485,23529,23574,23618,23663,23707,23751,23795,23839,
23883,23927,23971,24014,24058,24102,24145,24188,24232,24275,24318,24361,24404,24447,24490,24533,
24576,24618,24661,24703,24746,24788,24830,24872,24914,24957,24999,25040,25082,25124,25166,25207,
25249,25290,25332,25373,25415,25456,25497,25538,25579,25620,25661,25702,25742,25783,25824,25864,
25905,25945,25986,26026,26066,26106,26147,26187,26227,26267,26307,26346,26386,26426,26465,26505,
26545,26584,26624,26663,26702,26741,26781,26820,26859,26898,26937,26976,27014,27053,27092,27131,
27169,27208,27246,27285,27323,27362,27400,27438,27476,27514,27553,27591,27629,27666,27704,27742,
27780,27818,27855,27893,27930,27968,28005,28043,28080,28118,28155,28192,28229,28266,28303,28340,
28377,28414,28451,28488,28525,28562,28598,28635,28672,28708,28745,28781,28817,28854,28890,28926,
28963,28999,29035,29071,29107,29143,29179,29215,29251,29287,29322,29358,29394,29429,29465,29501,
29536,29572,29607,29642,29678,29713,29748,29784,29819,29854,29889,29924,29959,29994,30029,30064,
30099,30134,30168,30203,30238,30273,30307,30342,30376,30411,30445,30480,30514,30548,30583,30617,
30651,30685,30720,30754,30788,30822,30856,30890,30924,30958,30991,31025,31059,31093,31126,31160,
31194,31227,31261,31294,31328,31361,31395,31428,31461,31495,31528,31561,31595,31628,31661,31694,
31727,31760,31793,31826,31859,31892,31925,31957,31990,32023,32056,32088,32121,32154,32186,32219,
32251,32284,32316,32349,32381,32414,32446,32478,32510,32543,32575,32607,32639,32671,32703,32735
};
/******************************************************************************/
/*
 * ATAN Table      
 * ATAN_TAB[x] = atan(x)  0 <= x <= 1 (0 <= x <= 32768)
 *          0 <= atan(x) <= 45deg
*/
/******************************************************************************/
S16 ATAN_TAB[ATAN_TABLE_LEN] = {
0,81,162,244,325,407,488,569,651,732,813,894,974,1055,1136,1216,
1297,1377,1457,1537,1616,1696,1775,1854,1933,2011,2090,2168,2246,2323,2401,2478,
2555,2631,2708,2784,2859,2935,3010,3084,3159,3233,3307,3380,3453,3526,3598,3670,
3742,3813,3884,3954,4024,4094,4164,4233,4301,4369,4437,4505,4572,4638,4704,4770,
4836,4901,4965,5029,5093,5156,5219,5282,5344,5406,5467,5528,5588,5648,5708,5767,
5826,5884,5942,6000,6057,6114,6170,6226,6282,6337,6391,6446,6500,6553,6606,6659,
6711,6763,6815,6866,6917,6967,7017,7067,7116,7165,7214,7262,7310,7357,7404,7451,
7497,7543,7589,7634,7679,7724,7768,7812,7855,7898,7941,7984,8026,8068,8109,8151,
8191
};
//==========================================================================================================
// Local macros
//==========================================================================================================

//==========================================================================================================
// Local types
//==========================================================================================================

//==========================================================================================================
// Local data
//==========================================================================================================
register int DSP_ACCU_A asm("A");   // DSP ENGINE ACUMULATOR "A"
//==========================================================================================================
// Constant Local Data
//==========================================================================================================

//==========================================================================================================
// Constant exported data                                                     
//==========================================================================================================

//==========================================================================================================
// Exported Data
//==========================================================================================================

//==========================================================================================================
// Exported Data in Parlist
//==========================================================================================================

//==========================================================================================================
// Exported Data in Parlist -  Stored in EEPROM
//==========================================================================================================

//==========================================================================================================
// Local Functions Prototypes
//==========================================================================================================


//==========================================================================================================
//
//                                  E X P O R T E D    F U N C T I O N S
//
//==========================================================================================================
//==========================================================================================================
// Parameters: iY, iX - orthogonal vectors  0 <= iX <= 1 -> (0 <= iX <= 32768)
//
// Return: Angle * 65536 angle = atan(iY/iX)
//
// Description:     ATAN function of two orthogonal vectors
//                  ATAN Algorithm Clarification:
//                  y = atan(x), where x is two bytes signed value
//                  
//                  iArgu = (y/x)*32768 - scaled argument to atan function, angle = atan [iArgu]
//                  Let assume that iArgu is represented by fractional Q8.8 format 
//                    Uper 8 bytes of iArgu are integer part. Because 0 <= iArgu <= 32768 we have
//                  only 7 meaning bits from upper part of iArgu -> they are used to extract atan (iArgu)
//                  from ATAN_TAB table.
//                  Lower 8 bits are mantissa of DSP_ACCU_A (y/x). They are used to linear approximation 
//                  of DSP_ACCU_A between two points of ATAN_TAB table. Low 8 bits are scaled by 256 to fit 
//                  of U16 value.
//==========================================================================================================
U16 ATAN(S16 iY, S16 iX)
{
 	U16 iArgu;
   	U16 iTemp;
	U16 uArguComma;

	if (iX >= 0)
	{
		if (iY >= 0)      
		{
			/*----------------------------------------------------------------------------*/
			/* Quadrant I     0-90deg   (0-PI/2)                                          */
			/*----------------------------------------------------------------------------*/
        	 if (iX >= iY)	/* Sector 1 0-45deg        	*/
            {
	            iArgu = (sdiv_32( ((U32)iY<<16)>>1, iX+1) );  	// iArgu = (iY * 32768) / iX. Add 1 to iX, to avoid iArgu = 0.
			    uArguComma = iArgu << (DEC_PLACES_BEFORE + 1);			// Mantissa part. Only low 8 bits form iArgu scaled by 256. Used for approximation
			    iArgu 	 >>= DEC_PLACES_AFTER;							// iArgu / 256. iArgu max = 32768. 32768/256 = 128 -> Atan Table Length
  				iTemp 	   = ATAN_TAB[iArgu];							// Extract value from table - iTemp = atan(iArgu)
  				
            	return( iTemp + ((U32)(((U16)ATAN_TAB[iArgu+1] - iTemp) * uArguComma) >> 16) ); // Linear approximation between two points of table
            	//                                                      * iArgu*256  / 65536
			}
			else		 	/* Sector 2	45-90deg		*/
			{
            	iArgu = (sdiv_32( ((U32)iX<<16)>>1, iY));
			    uArguComma = iArgu << (DEC_PLACES_BEFORE + 1);
			    iArgu    >>= DEC_PLACES_AFTER;
  				iTemp      = ATAN_TAB[iArgu];

		      return ( ( qHalf_PI_deg - iTemp) - ((U32)(((U16)ATAN_TAB[iArgu+1] - iTemp) * uArguComma) >> 16) );
			}
		}
		else
		{
			/*----------------------------------------------------------------------------*/
			/* Quandrant IV	270-360deg     (3*PI/2 - 2PI)                                 */
			/*----------------------------------------------------------------------------*/				
			iY = -iY;
			if (iX >= iY)	/* Sector 8  315-360deg	  		*/
			{ 
				iArgu = (sdiv_32( ((U32)iY<<16)>>1, iX+1)); /* Add 1 to avoid overflow*/
			    uArguComma = iArgu<<(DEC_PLACES_BEFORE + 1);
			    iArgu    >>= DEC_PLACES_AFTER;
  				iTemp      = ATAN_TAB[iArgu];

            	return (-iTemp - ((U32)(((U16)ATAN_TAB[iArgu+1] - iTemp) * uArguComma) >> 16) );
			}
			else			/* Sector 7	270-315deg			*/
			{
            	iArgu = (sdiv_32( ((U32)iX<<16)>>1, iY));
			    uArguComma = iArgu<<(DEC_PLACES_BEFORE + 1);
			    iArgu >>= DEC_PLACES_AFTER;
  				iTemp =   ATAN_TAB[iArgu];

				return ( (-qHalf_PI_deg + iTemp) + ((U32)(((U16)ATAN_TAB[iArgu+1] - iTemp) * uArguComma) >> 16) );
			}
		}
	}
	else /* iX < 0 */
	{					
      	iX = -iX;
	
		if ( iY >= 0)
		{
			/*----------------------------------------------------------------------------*/
			/* Quadrant II 90-180deg		(PI/2 - PI)                                   */
			/*----------------------------------------------------------------------------*/
			if (iX >= iY)	/* Sector 4	 135-180deg  	*/
			{
            	iArgu = (sdiv_32( ((U32)iY<<16)>>1, iX+1)); 
			    uArguComma = iArgu<<(DEC_PLACES_BEFORE + 1);
			    iArgu    >>= DEC_PLACES_AFTER;
  				iTemp      = ATAN_TAB[iArgu];
  				
            	return ( ( qPI_deg - iTemp) - ((U32)(((U16)ATAN_TAB[iArgu+1] - iTemp) * uArguComma) >> 16 ) );
			}
			else			/* Sector 3	 90-135deg	 	*/
			{
            	iArgu = (sdiv_32( ((U32)iX<<16)>>1, iY));
			    uArguComma = iArgu<<(DEC_PLACES_BEFORE + 1);
			    iArgu    >>= DEC_PLACES_AFTER;
  				iTemp      = ATAN_TAB[iArgu];

            	return ( ( qHalf_PI_deg + iTemp) + ( (U32)(((U16)ATAN_TAB[iArgu+1] - iTemp) * uArguComma) >> 16 ) );
			}
		}
		else
		{
			/*----------------------------------------------------------------------------*/
			/* Quadrant III 180-270deg		(PI - 3*PI/2)                                 */
			/*----------------------------------------------------------------------------*/
			iY = -iY;
			
			if (iX >= iY)	/* Sector 5	 180-225deg    */
			{
            	iArgu = (sdiv_32( ((U32)iY<<16)>>1, iX+1));
			    uArguComma = iArgu << (DEC_PLACES_BEFORE + 1);
			    iArgu    >>= DEC_PLACES_AFTER;
  				iTemp      = ATAN_TAB[iArgu];

            	return ( (-qPI_deg + iTemp) + ((U32)(((U16)ATAN_TAB[iArgu+1] - iTemp) * uArguComma) >> 16) );
			}
			else			/* Sector 6	225-270deg		*/
			{
            	iArgu = (sdiv_32( ((U32)iX<<16)>>1, iY));
			    uArguComma = iArgu << (DEC_PLACES_BEFORE + 1);
			    iArgu >>= DEC_PLACES_AFTER;
  				iTemp =   ATAN_TAB[iArgu];

            	return ( (-qHalf_PI_deg - iTemp) - ((U32)(((U16)ATAN_TAB[iArgu+1] - iTemp) * uArguComma) >> 16) );
			}
		}
	}
}// end ATAN()
//==========================================================================================================
// Parameters: x*32768 0 <= x <= 1
//
// Return: sqrt(x) * 32768 
//
// Description: Square root of integer
//==========================================================================================================
S16 sqrt_16(U16 rad)
{
	S16 sqr;
	//if value < 0.25(8192) lookup first sqrt table, else lookup second sqrt table 0.25 <= x <= 1
	sqr = ( rad <= 8192 ? SQRT_TAB[rad >> (15 - SQRT_LEN_DIV - 2)] : SQRT_TAB2[rad >> (15 - SQRT_LEN_DIV)] );
	//                     rad / 2^4(16)   (15 - 9 - 2 = 4)          rad / 2^6(64)    (15 - 9 = 6) 
	return(sqr);

}
//==========================================================================================================
// Parameters: x*2^31	 0 <= x <= 1
//
// Return: sqrt(x) * 32768
//
// Description: Square root of Long integer
//==========================================================================================================
S16 sqrt_32(U32 rad)
{
	S16 ra;
	S16 sqr;
	U16 scale_coeff;
	
	if(rad == 0) return(0);
	
	// We must represent rad as rad = (31...16)(15...0) -> four byte value
	//                          rad = (   Hi  )(  Lo  )
	// rad = Lo * scale_coeff;
	// where, 0 <= scale_coeff <= 7
	// 
	
	scale_coeff = 7;
	
	// In this loop divide rad by 4 in every cycle to fit rad in S16 value, and decrement scale_coeff with 1
	for(rad >>= 1;rad > 32767;rad >>= 2) // first divide rad/2 before run loop to avoid dummy loops.
	{
		--scale_coeff;	// decrement square root product divider
	}
	
	ra = (S16)rad;
	
	sqr = ( ra <= 8192 ? SQRT_TAB[ra>>(15-SQRT_LEN_DIV-2)] : SQRT_TAB2[ra>>(15-SQRT_LEN_DIV)] );
	
	//divide sqr to fit sqrt(U32) to SQRT(16)
	return(sqr >> scale_coeff);

}
//==========================================================================================================
// Parameters: 0 < x < 32768
//
// Return: Pow(x)
//
// Description: Power of integer
//==========================================================================================================
U32 pow_16(S16 x, U16 n)
{
	U32 power;
	U16 nl;
	
	nl = n;
	power = absi(x);
	
	while((--nl) != 0)
	{
		power *= absi(x);
	}

	return(power);
}
//==========================================================================================================
// Parameters: A -> S32, B -> S16. 
//
// Return: Computes the quotient num / den
//
// Description: Signed Long Integer Division
//              Note that DSP Engine accumulators are in super-saturation mode !!!
//==========================================================================================================
S16 sdiv_32(_IN_ S32 s32Divident_long, _IN_ S16 s16Divider)
{
	S16 res;
	
    res = ( s16Divider != 0 ?  __builtin_divsd(s32Divident_long, s16Divider) : -1 );
	
	return(res);
}
//==========================================================================================================
// Parameters: A -> S32, B -> S16. 
//
// Return: Computes the quotient num / den
//
// Description: Unsigned Long Integer Division
//              Note that DSP Engine accumulators are in super-saturation mode !!!
//==========================================================================================================
S16 udiv_32(_IN_ U32 u32Divident_long, _IN_ U16 u16Divider)
{
    S16 res;

    res = ( u16Divider != 0 ?  __builtin_divud(u32Divident_long, u16Divider) : -1 );

    return(res);
}
//==========================================================================================================
// Parameters: A, B
//
// Return: Fractional Product ->(A*B) >> 15. Note that CORCONbits.IF = 0 -> DSP Fractional Operations
//
// Description: Signed Fractional Multiplication
//              Note that DSP Engine accumulators are in super-saturation mode !!!
//==========================================================================================================
Q15 fmul_q15(Q15 qA, Q15 qB)
{
	Q15 res;
  
	CORCONbits.IF = 0; // Put DSP Engine in fractional mode
  CORCONbits.US	= 0;
	
	// clear it out.. this is special since it's 40 bits long...
	DSP_ACCU_A = __builtin_clr(); 	// clear out accumulator
	
	// do the multiplication.. DSP_ACCU_A stored in 40 bit accumulator
	DSP_ACCU_A = __builtin_mpy((S16)qA, (S16)qB, NULL, NULL, 0, NULL, NULL, 0);
	// get value out and put into fractional C.
	res = __builtin_sacr(DSP_ACCU_A, 0);
	
	return(res);
}

//==========================================================================================================
// Parameters: A, B
//
// Return: Fractional Product ->(A*B) >> 15. Note that CORCONbits.IF = 0 -> DSP Fractional Operations
//
// Description: Unsigned Fractional Multiplication
//              Note that DSP Engine accumulators are in super-saturation mode !!!
//==========================================================================================================
U16 fmul_qu15(U16 quA, U16 quB)
{
  U16 res;

	CORCONbits.IF = 0; // Put DSP Engine in fractional mode
	CORCONbits.US	= 1; // unsigned mode
  
	// clear it out.. this is special since it's 40 bits long...
	DSP_ACCU_A = __builtin_clr(); 	// clear out accumulator
	
	// do the multiplication.. DSP_ACCU_A stored in 40 bit accumulator
	DSP_ACCU_A = __builtin_mpy(quA, quB, NULL, NULL, 0, NULL, NULL, 0);
	// get value out and put into fractional C.
	res = __builtin_sacr(DSP_ACCU_A, 0);
	
	return(res);
}

//==========================================================================================================
// Parameters: (S16)A, (S16)B
//
// Return: (S32)Long = A*B
//
// Description: Signed Integer Multiplication
//              Note that DSP Engine accumulators are in super-saturation mode !!!
//==========================================================================================================
S32 mul_s16(S16 A, S16 B)
{
	S32 res;
  
	CORCONbits.IF = 1; // Put DSP Engine in Integer mode
  CORCONbits.US	= 0;
	
	// clear it out.. this is special since it's 40 bits long...
	//DSP_ACCU_A = __builtin_clr(); 	// clear out accumulator
	
	// do the multiplication.. DSP_ACCU_A stored in 40 bit accumulator
	res = __builtin_mulss(A, B);
	// get value out 
	//res = (S32)__builtin_sacr(DSP_ACCU_A, 0);

	return(res);
}
//==========================================================================================================
// Parameters: void
//
// Return: void
//
// Description: DSP Engine Init
//==========================================================================================================
void DSP_Engine_Init(void)
{
	CORCONbits.PSV  	= 1;       // Turn On PSV Space visibility
	CORCONbits.SATA 	= 1;       // DSP Accumulator A in Super Saturation Mode 
	CORCONbits.SATB 	= 1;       // DSP Accumulator B in Super Saturation Mode 
	CORCONbits.ACCSAT 	= 1;     // Accumulator Saturation Mode Select bit -> 1 = 9.31 saturation (super saturation)		
	CORCONbits.IF	 	= 1;         // DSP In Integer mode
	CORCONbits.RND      = 1;     // 1 = Biased (conventional) rounding enabled
	CORCONbits.US	 	= 0;       // DSP In Signed Mode
}
//==========================================================================================================
//                                                                            
//                                     L O C A L    F U N C T I O N S                   
//                                                                            
//==========================================================================================================
//==========================================================================================================
// Parameters: void
//
// Return: void
//
// Description: 
//==========================================================================================================
