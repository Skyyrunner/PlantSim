#pragma once

enum MONTHS{ JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };
enum SOILTYPE { stCLAY = 1, stSANDYCLAY, stSILTYCLAY, stCLAYLOAM, stSILTYCLAYLOAM, stSANDYCLAYLOAM, stLOAM, stSILTLOAM, stSANDYLOAM, stLOAMYSAND, stSAND, stSILT };
enum SOILTYPEGROUP { stgCLAYGROUP = 1, stgSANDGROUP, stgLOAMGROUP, stgSILTGROUP };
enum MOORE { NONE = -1, TOP = 0, TOPLEFT, LEFT, BOTTOMLEFT, BOTTOM, BOTTOMRIGHT, RIGHT, TOPRIGHT };
enum GROWTHSTAGES { GERMINATION = 0, LEAFDEV = 1, SIDESHOOTS = 2, STEMGROWTH = 3, VEGETATIVE = 4, INFLORESCENCE = 5, FLOWERING = 6, FRUITING = 7, RIPENING = 8, MATURITY = 9 };
enum GENEDOMINANCE { DOMINANT = 1, RECESSIVE = 0 };
enum PROMPTSTATE {promptNONE = 0, promptWAITING, promptRECIEVED};