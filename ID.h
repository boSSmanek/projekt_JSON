/*
 * ID.h
 *
 *  Created on: 12 gru 2018
 *      Author: ogieglo.m
 */

#ifndef ID_H_
#define ID_H_

#include <stdint.h>
#include "ioInterface/ObjectID.h"

class ID
{
public:

    static const uint16_t HASH = 0x075E;

    enum Global
    {
        ROOT_MENU = 999,
        ROOT_COG_MAIN_SCREEN_SELECTOR = 1313,
        COG_MAIN_SCREEN_SELECTOR_DHW_SCREEN = 1323,
        COG_MAIN_SCREEN_SELECTOR_BOILER_SCREEN = 1314,
        COG_MAIN_SCREEN_SELECTOR_BUFFER_SCREEN = 1315,
        COG_MAIN_SCREEN_SELECTOR_HEATING_DEMAND = 1321,
        COG_MAIN_SCREEN_SELECTOR_LOCKS_SCREEN = 1322,
        COG_MAIN_SCREEN_SELECTOR_VALVE_1SCREEN = 1319,
        COG_MAIN_SCREEN_SELECTOR_VALVE_2SCREEN = 1318,
        COG_MAIN_SCREEN_SELECTOR_VALVE_3SCREEN = 1316,
        COG_MAIN_SCREEN_SELECTOR_VALVE_4SCREEN = 1317,
        COG_MAIN_SCREEN_SELECTOR_VALVE_5SCREEN = 1320,
        COG_MAIN_SCREEN_SELECTOR_PRODUCER_SCREEN = 1349,
        ROOT_FIRING_UP = 1000,
        ROOT_DAMPING = 1001,
        ROOT_TRAY_IS_FULL = 1200,
        ROOT_TEMPERATURE_SETTINGS = 1002,
        TEMPERATURE_SETTINGS_CH_TEMP_SET = 1003,
        TEMPERATURE_SETTINGS_BOILER_HYSTERESIS = 1004,
        TEMPERATURE_SETTINGS_BURNER_TRESHOLD = 1288,
        ROOT_WORK_ALGORITHM = 1260,
        ROOT_HEATING_MODE = 1005,
        ROOT_MANUAL_MODE = 1006,
        MANUAL_MODE_FEEDER = 1007,
        MANUAL_MODE_FEEDER_STOCKER = 1008,
        MANUAL_MODE_FAN = 1009,
        MANUAL_MODE_FAN_SPEED = 1010,
        MANUAL_MODE_EXHAUST_FAN_IN_MANUAL_WORK = 1361,
        EXHAUST_FAN_IN_MANUAL_WORK_EXHAUST_FAN_IS_ON_IN_MANUAL_WORK = 1360,
        EXHAUST_FAN_IN_MANUAL_WORK_EXHAUST_FAN_SPEED_IN_MANUAL_WORK = 1362,
        MANUAL_MODE_IGNITER = 1011,
        MANUAL_MODE_GRATE = 1196,
        MANUAL_MODE_GRATE_OPEN = 1251,
        MANUAL_MODE_GRATE_CLOSE = 1250,
        MANUAL_MODE_PUMP_1 = 1012,
        MANUAL_MODE_PUMP_2 = 1013,
        MANUAL_MODE_PUMP_3 = 1014,
        MANUAL_MODE_PUMP_4 = 1015,
        MANUAL_MODE_PUMP_5 = 1016,
        MANUAL_MODE_POTENTIAL_FREE_CONTACT = 1017,
        MANUAL_MODE_MANUAL_BUILT_IN_VALVE_1 = 1018,
        MANUAL_BUILT_IN_VALVE_1_OPEN_VALVE_BUILT_IN_1 = 1019,
        MANUAL_BUILT_IN_VALVE_1_CLOSE_VALVE_BUILT_IN_1 = 1020,
        MANUAL_MODE_MANUAL_BUILT_IN_VALVE_2 = 1021,
        MANUAL_BUILT_IN_VALVE_2_OPEN_VALVE_BUILT_IN_2 = 1022,
        MANUAL_BUILT_IN_VALVE_2_CLOSE_VALVE_BUILT_IN_2 = 1023,
        MANUAL_MODE_MANUAL_ADD_VALVE_1 = 1262,
        MANUAL_ADD_VALVE_1_OPEN_VALVE_ADD_1 = 1263,
        MANUAL_ADD_VALVE_1_CLOSE_VALVE_ADD_1 = 1264,
        MANUAL_ADD_VALVE_1_PUMP_VALVE_ADD_1 = 1268,
        MANUAL_MODE_MANUAL_ADD_VALVE_2 = 1265,
        MANUAL_ADD_VALVE_2_OPEN_VALVE_ADD_2 = 1267,
        MANUAL_ADD_VALVE_2_CLOSE_VALVE_ADD_2 = 1266,
        MANUAL_ADD_VALVE_2_PUMP_VALVE_ADD_2 = 1269,
        MANUAL_MODE_MANUAL_ADD_VALVE_3 = 1297,
        MANUAL_ADD_VALVE_3_OPEN_VALVE_ADD_3 = 1298,
        MANUAL_ADD_VALVE_3_CLOSE_VALVE_ADD_3 = 1299,
        MANUAL_ADD_VALVE_3_PUMP_VALVE_ADD_3 = 1300,
        ROOT_MANUAL_MODE_UNAVAILABLE = 1191,
        ROOT_USTAWIENIA_EKRANU = 1032,
        USTAWIENIA_EKRANU_PRODUCER_SCREEN_OPTION_PASSWORD = 1235,
        USTAWIENIA_EKRANU_PRODUCER_SCREEN_OPTION = 1234,
        USTAWIENIA_EKRANU_CLOCK_SETTINGS = 1033,
        CLOCK_SETTINGS_TIME = 1034,
        CLOCK_SETTINGS_DATE = 1035,
        USTAWIENIA_EKRANU_JASNOSC_PRACA = 1036,
        USTAWIENIA_EKRANU_JASNOSC_WYGASZANIE = 1037,
        USTAWIENIA_EKRANU_DISPLAY_CONTRAST = 1336,
        USTAWIENIA_EKRANU_CZAS_WYGASZANIA = 1038,
        USTAWIENIA_EKRANU_DZWIEK_ALARMY = 1039,
        USTAWIENIA_EKRANU_DZWIEK_PRZYCISKI = 1040,
        USTAWIENIA_EKRANU_AKTUALIZACJA = 1041,
        USTAWIENIA_EKRANU_AKTUALIZACJA_EHOME = 1186,
        ROOT_SETTINGS_MENU = 1042,
        SETTINGS_MENU_MANUAL_BURNING = 1376,
        MANUAL_BURNING_MANUAL_BURNING_ON_OFF = 1377,
        SETTINGS_MENU_COEFFICIENTS = 1180,
        COEFFICIENTS_STOCKER_FEEDER_RATIO = 1181,
        COEFFICIENTS_MIN_FAN = 1224,
        COEFFICIENTS_MAX_FAN = 1225,
        COEFFICIENTS_POWER_FACTOR = 1311,
        SETTINGS_MENU_ETHERNET = 1043,
        ETHERNET_ETHERNET_ON_OFF = 1044,
        ETHERNET_WYBOR_SIECI_WIFI = 1312,
        ETHERNET_REGISTRATION = 1045,
        ETHERNET_ETHERNET_DETAILS = 1194,
        ETHERNET_ETHERNET_ADVANCED = 1193,
        ETHERNET_ADVANCED_DHCP = 1046,
        ETHERNET_ADVANCED_IP = 1047,
        ETHERNET_ADVANCED_MASK = 1048,
        ETHERNET_ADVANCED_GATEWAY = 1049,
        ETHERNET_ADVANCED_DNS = 1050,
        SETTINGS_MENU_RELAY_SETTINGS = 1190,
        RELAY_SETTINGS_RELAY_1 = 20000,
        RELAY_SETTINGS_RELAY_2 = 20500,
        RELAY_SETTINGS_RELAY_3 = 21000,
        RELAY_SETTINGS_RELAY_4 = 21500,
        RELAY_SETTINGS_RELAY_5 = 22000,
        RELAY_SETTINGS_RELAY_6 = 22500,
        SETTINGS_MENU_VALVE_SETTINGS = 1189,
        VALVE_SETTINGS_VALVE_1 = 10000,
        VALVE_SETTINGS_VALVE_2 = 10500,
        VALVE_SETTINGS_VALVE_3 = 11000,
        VALVE_SETTINGS_VALVE_4 = 11500,
        VALVE_SETTINGS_VALVE_5 = 12000,
        SETTINGS_MENU_ROOM_CONTROLLERS = 1174,
        ROOM_CONTROLLERS_ROOM_CONTROLLER_1 = 1175,
        ROOM_CONTROLLERS_ROOM_CONTROLLER_2 = 1176,
        SETTINGS_MENU_INSTALLER_FACTORY_SETTINGS = 1188,
        SETTINGS_MENU_FUEL_METER_CALLIBRATION = 1197,
        FUEL_METER_CALLIBRATION_CALLIBRATION_TRAY_IS_FULL = 1198,
        FUEL_METER_CALLIBRATION_CALLIBRATION_TRAY_IS_EMPTY = 1199,
        SETTINGS_MENU_HEAT_DEMAND = 1282,
        SETTINGS_MENU_BURNER_WORK_PLAN = 1292,
        BURNER_WORK_PLAN_BURNER_WORK_PLAN_IS_ON = 1293,
        BURNER_WORK_PLAN_WORK_PLAN_MON_SUN = 1294,
        SETTINGS_MENU_PERIODICAL_CLEANING = 1327,
        PERIODICAL_CLEANING_IS_ON = 1328,
        PERIODICAL_CLEANING_CLEANING_PERIOD = 1329,
        SETTINGS_MENU_BLOW_BY_DURNING_OPERATION = 1330,
        BLOW_BY_DURNING_OPERATION_TURN_ON_BLOW_BY_DURNING_OPERATION = 1331,
        BLOW_BY_DURNING_OPERATION_BLOW_BY_DURNING_OPERATION_TIME = 1332,
        BLOW_BY_DURNING_OPERATION_BLOW_BY_DURNING_PAUSE_TIME = 1333,
        BLOW_BY_DURNING_OPERATION_BLOW_BY_DURNING_FAN = 1334,
        SETTINGS_MENU_EXHAUST_FAN = 1363,
        EXHAUST_FAN_EXHAUST_FAN_IS_ON = 1366,
        EXHAUST_FAN_EXHAUST_FAN_MIN = 1364,
        EXHAUST_FAN_EXHAUST_FAN_MAX = 1365,
        EXHAUST_FAN_EXHAUST_FAN_DIALOG_VERSION = 1367,
        EXHAUST_FAN_DIALOG_VERSION_EXHAUST_FAN_VERSION = 1368,
        ROOT_SERVICE_MENU = 1051,
        SERVICE_MENU_BOILER_POWER = 1280,
        SERVICE_MENU_BOILER_SETTINGS = 1123,
        BOILER_SETTINGS_IGNITION_SETTINGS = 1124,
        IGNITION_SETTINGS_FIRE_TEST = 1378,
        FIRE_TEST_FIRE_TEST_TIME = 1379,
        FIRE_TEST_DETECTION_TIME = 1380,
        IGNITION_SETTINGS_IGNITION_BLOWING = 1154,
        IGNITION_BLOWING_DURATION_BLOWING_PHASE = 1142,
        IGNITION_BLOWING_FAN_POWER_BLOWING_PHASE = 1153,
        IGNITION_SETTINGS_IGNITION_FEEDING = 1155,
        IGNITION_FEEDING_DURATION_FEEDING_PHASE = 1143,
        IGNITION_FEEDING_FAN_POWER_FEEDING_PHASE = 1156,
        IGNITION_FEEDING_PERCENT_FEEDER_WORK = 1168,
        IGNITION_SETTINGS_IGNITION_DELAY = 1356,
        IGNITION_DELAY_DURATION_DELAY_PHASE = 1358,
        IGNITION_SETTINGS_IGNITION_STABILIZATION = 1160,
        IGNITION_STABILIZATION_DURATION_STABILIZATION_PHASE = 1146,
        IGNITION_STABILIZATION_POWER_STABILIZATION_PHASE = 1161,
        IGNITION_STABILIZATION_START_POWER_STABILIZATION_STATE = 1166,
        IGNITION_SETTINGS_IGNITION_GAS_SENSOR = 1163,
        IGNITION_GAS_SENSOR_WITH_FIRE = 1164,
        IGNITION_GAS_SENSOR_THRESHOLD_GAS_HOLD = 1165,
        IGNITION_GAS_SENSOR_INCREASE_GAS_TEMPERATURE = 1167,
        IGNITION_GAS_SENSOR_FIRING_UP_BRIGHTNESS = 1226,
        IGNITION_SETTINGS_IGNITER_SETTINGS = 1157,
        IGNITER_SETTINGS_DURATION_IGNITER_WORK = 1144,
        IGNITER_SETTINGS_FAN_POWER_AWAITING_PHASE = 1159,
        IGNITER_SETTINGS_IGNITION_ATTEMPS = 1162,
        BOILER_SETTINGS_WORK_ALGORITHMS_SETTINGS = 1283,
        WORK_ALGORITHMS_SETTINGS_STANDARD_WORK = 1126,
        STANDARD_WORK_WORK_POWER = 1134,
        STANDARD_WORK_SUSTAIN_POWER = 1135,
        STANDARD_WORK_HYSTERESIS = 1136,
        WORK_ALGORITHMS_SETTINGS_SIGMA_SETTINGS = 1127,
        SIGMA_SETTINGS_THRESHOLD_MIN = 1128,
        SIGMA_SETTINGS_THRESHOLD_MAX = 1129,
        SIGMA_SETTINGS_POWER_STEP_MAX = 1130,
        SIGMA_SETTINGS_TEMP_STAGNATION = 1131,
        SIGMA_SETTINGS_TIME_OVERHEAT = 1132,
        BOILER_SETTINGS_DAMPING_SETTINGS = 1125,
        DAMPING_SETTINGS_DAMPING_BRIGHTNESS_TRESHOLD = 1335,
        DAMPING_SETTINGS_MIN_DURATION = 1137,
        DAMPING_SETTINGS_TIME_AFTERBURNING = 1138,
        DAMPING_SETTINGS_POWER_AFTERBURNING = 1140,
        DAMPING_SETTINGS_TIME_EXHAUST = 1139,
        DAMPING_SETTINGS_POWER_EXHAUST = 1141,
        BOILER_SETTINGS_GRATE = 1206,
        GRATE_GRATE_TYPE = 1271,
        GRATE_GRATE_TYPE_UNAVAILABLE = 1272,
        GRATE_GRATE_HALL = 1256,
        GRATE_BEFORE_IGNITION = 1208,
        GRATE_AFTER_DAMPING_MENU = 1276,
        AFTER_DAMPING_MENU_IS_ON_DAMPING = 1209,
        AFTER_DAMPING_MENU_CYCLES_COUNT_DAMPING = 1277,
        GRATE_RETURN_TIME_DELAY = 1261,
        GRATE_OPEN_TIME = 1212,
        GRATE_GRATE_AT_WORK = 1207,
        GRATE_AT_WORK_IS_ON_WORK = 1210,
        GRATE_AT_WORK_WORK_TIME = 1211,
        GRATE_AT_WORK_CLEANING_FREQUENCY = 1213,
        GRATE_AT_WORK_CYCLES_COUNT_WORK = 1275,
        GRATE_HALL_TIMEOUT = 1273,
        BOILER_SETTINGS_FIRE_TEST = 1350,
        FIRE_TEST_TIME_TO_RETURN_TO_WORK = 1351,
        FIRE_TEST_TIME_TO_RETURN_TO_TEST = 1352,
        FIRE_TEST_DURATION_FIRE_TEST = 1353,
        FIRE_TEST_POWER_IN_FIRE_TEST = 1354,
        BOILER_SETTINGS_FLAME_CONTROL_TIME = 1252,
        BOILER_SETTINGS_CURRENT_MEASUREMENT_SETTINGS = 1284,
        CURRENT_MEASUREMENT_SETTINGS_CURRENT_MEASUREMENT = 1285,
        CURRENT_MEASUREMENT_SETTINGS_MIN_WENT_CURRENT = 1286,
        CURRENT_MEASUREMENT_SETTINGS_MIN_HEATER_CURRENT = 1287,
        SERVICE_MENU_FAN_SETTINGS_UNAVAILABLE = 1355,
        SERVICE_MENU_FAN_SETTINGS = 1238,
        FAN_SETTINGS_MIN_PRODUCER_GEAR = 1239,
        FAN_SETTINGS_MAX_PRODUCER_GEAR = 1240,
        FAN_SETTINGS_MIN_PRODUCER_RPM = 1241,
        FAN_SETTINGS_MAX_PRODUCER_RPM = 1242,
        SERVICE_MENU_HALLOTRON_SETTINGS = 1289,
        HALLOTRON_SETTINGS_HALLOTRON_ON = 1290,
        HALLOTRON_SETTINGS_IMPULSES_PER_FAN_ROTATION = 1291,
        SERVICE_MENU_OPERATION_PARAMETERS = 1214,
        OPERATION_PARAMETERS_MIN_POWER = 1216,
        MIN_POWER_FEEDER_WORK_TIME_MIN = 1220,
        MIN_POWER_FEEDER_PAUSE_TIME_MIN = 1221,
        MIN_POWER_FAN_GEAR_MIN = 1222,
        OPERATION_PARAMETERS_MAX_POWER = 1215,
        MAX_POWER_FEEDER_WORK_TIME_MAX = 1217,
        MAX_POWER_FEEDER_PAUSE_TIME_MAX = 1218,
        MAX_POWER_FAN_GEAR_MAX = 1219,
        OPERATION_PARAMETERS_POWER_GAIN = 1223,
        SERVICE_MENU_FEEDER_SENSOR_ON = 1243,
        SERVICE_MENU_TEMPERATURE_SETTINGS_SERVICE = 1244,
        TEMPERATURE_SETTINGS_SERVICE_FEEDER_ALARM_TEMPERATURE = 1245,
        TEMPERATURE_SETTINGS_SERVICE_ANTIFREEZE_TEMPERATURE = 1257,
        TEMPERATURE_SETTINGS_SERVICE_ALARM_TEMPERATURE_PUMP_CH = 1258,
        TEMPERATURE_SETTINGS_SERVICE_BOILER_ALARM_TEMPERATURE = 1259,
        SERVICE_MENU_SERVICE_FACTORY_SETTINGS = 1187,
        SERVICE_MENU_SERVICE_FACTORY_SETTINGS_EXTENED = 1371,
        SERVICE_FACTORY_SETTINGS_EXTENED_SERVICE_FACT_EXTMAIN_MENU = 1372,
        SERVICE_FACTORY_SETTINGS_EXTENED_SERVICE_FACT_EXTSETTINGS_MENU = 1373,
        SERVICE_FACTORY_SETTINGS_EXTENED_SERVICE_FACT_EXTSERVICE_MENU = 1374,
        SERVICE_FACTORY_SETTINGS_EXTENED_SERVICE_FACT_EXTVALVE_MENU = 1375,
        ROOT_FACTORY_SETTINGS = 1077,
        ROOT_LANGUAGE_VERSION = 1078,
        LANGUAGE_VERSION_PL = 1079,
        LANGUAGE_VERSION_ENG = 1080,
        LANGUAGE_VERSION_UKR = 1281,
        LANGUAGE_VERSION_CZE = 1246,
        LANGUAGE_VERSION_SK = 1247,
        LANGUAGE_VERSION_DE = 1248,
        LANGUAGE_VERSION_RUS = 1249,
        ROOT_INFORMACJA = 1081,
        ROOT_FORCE_DAMPING = 1169,
        VALUES_CALLBACK_FAN_RECALCULATOR = 1359,
        VALUES_FAN_PID_PARAM_PWM = 1348,
        VALUES_FAN_PID_PARAM_MN = 1347,
        VALUES_FAN_PID_PARAM_SN = 1346,
        VALUES_FAN_PID_PARAM_PSP = 1345,
        VALUES_FAN_PID_PARAM_PI = 1344,
        VALUES_FAN_PID_PARAM_PP = 1343,
        VALUES_FAN_PID_CALIBRATE_C = 1342,
        VALUES_FAN_PID_CALIBRATE_KSP = 1341,
        VALUES_FAN_PID_CALIBRATE_KD = 1340,
        VALUES_FAN_PID_CALIBRATE_KI = 1339,
        VALUES_FAN_PID_CALIBRATE_KP = 1338,
        VALUES_TURN_OFF_FAN = 1326,
        VALUES_SETUP_FAN_RPM = 1325,
        VALUES_FORCE_FAN_MODE = 1324,
        VALUES_HEAT_DEMAND_BLOCK_LIST = 1303,
        VALUES_PUMP_STATE_VALUE_1 = 1305,
        VALUES_PUMP_STATE_VALUE_2 = 1306,
        VALUES_PUMP_STATE_VALUE_3 = 1307,
        VALUES_PUMP_STATE_VALUE_4 = 1308,
        VALUES_PUMP_STATE_VALUE_5 = 1309,
        VALUES_PUMP_STATE_VALUE_6 = 1310,
        VALUES_UPDATE_BLOCK_ID = 1182,
        VALUES_UPDATE_TYPE = 1183,
        VALUES_UPDATE_MANUF = 1184,
        VALUES_UPDATE_CURRENT_BLOCK = 1185,
        VALUES_JASNOSC_PRACA_EEPROM = 1082,
        VALUES_JASNOSC_WYGASZANIE_EEPROM = 1083,
        VALUES_DISP_CONTRAST_EEPROM = 1337,
        VALUES_JEZYK_EEPROM = 1084,
        VALUES_DZWIEK_ALARM_EEPROM = 1085,
        VALUES_DZWIEK_PRZYCISKI_EEPROM = 1086,
        VALUES_CZAS_WYGASZANIE_EEPROM = 1087,
        VALUES_RELAYS = 1088,
        VALUES_RELAYS_2 = 1270,
        VALUES_BURNER_STATE = 1089,
        VALUES_ENTER_TO_MANUAL_MODE = 1090,
        VALUES_CLEAR_ALARMS = 1091,
        VALUES_BOILER_ALARMS = 1092,
        VALUES_PUMP_1PUMP_2PUMP_3ALARMS = 1170,
        VALUES_PUMP_4PUMP_5ALARMS = 1171,
        VALUES_VALVE_1VALVE_2ALARMS = 1172,
        VALUES_ADDITIONAL_VALVE_1ADDITIONAL_VALVE_2ALARMS = 1173,
        VALUES_MESSAGES = 1093,
        VALUES_SENSOR_CH = 1094,
        VALUES_SENSOR_DHW = 1095,
        VALUES_SENSOR_FUMES = 1096,
        VALUES_SENSOR_FEEDER = 1097,
        VALUES_SENSOR_RETURN = 1098,
        VALUES_SENSOR_WEATHER = 1100,
        VALUES_SENSOR_VALVE_1 = 1101,
        VALUES_SENSOR_VALVE_2 = 1102,
        VALUES_SENSOR_ADD_1 = 1103,
        VALUES_SENSOR_ADD_2 = 1104,
        VALUES_SENSOR_MOSFET = 1106,
        VALUES_SENSOR_FIRE = 1149,
        VALUES_CURRENT_SENSOR = 1236,
        VALUES_MODULE_VERSION = 1107,
        VALUES_DATE = 1108,
        VALUES_TIME = 1109,
        VALUES_ETHERNET_REGISTRATION_CODE = 1110,
        VALUES_IP_L = 1111,
        VALUES_IP_H = 1112,
        VALUES_MASK_L = 1113,
        VALUES_MASK_H = 1114,
        VALUES_GATEWAY_H = 1115,
        VALUES_GATEWAY_L = 1116,
        VALUES_DNS_L = 1117,
        VALUES_DNS_H = 1118,
        VALUES_MAC_L = 1119,
        VALUES_MAC_M = 1120,
        VALUES_MAC_H = 1121,
        VALUES_ETHERNET_VERSION = 1122,
        VALUES_ROOM_CONTROLLER_1VALUE = 1177,
        VALUES_ROOM_CONTROLLER_2VALUE = 1178,
        VALUES_ROOM_CONTROLLER_MAIN_SCREEN_VALUE = 1179,
        VALUES_VISIBILITY_FLAGS = 1192,
        VALUES_DAMPING_CAUSE = 1195,
        VALUES_FUEL_METER_PERCENTAGE = 1201,
        VALUES_FUEL_METER_CALLIBRATION_STATE = 1202,
        VALUES_TIME_TO_END_STAGE = 1203,
        VALUES_FAN_SPEED = 1204,
        VALUES_MICROCONTROLLER_TYPE = 1205,
        VALUES_DIGITAL_INPUT_STATES = 1227,
        VALUES_CURRENT_FAN_RPM = 1228,
        VALUES_CURRENT_POWER = 1229,
        VALUES_GOAL_POWER = 1230,
        VALUES_CURRENT_FEEDER_WORK_TIME = 1231,
        VALUES_CURRENT_FEEDER_PAUSE_TIME = 1232,
        VALUES_ENTER_TO_SENSOR_SCREEN = 1237,
        VALUES_PROTO_VERSION = 1278,
        VALUES_PROTO_CUSTOMER = 1279,
    };

    enum Relay
    {
        RELAY_DEVICE_TYPE = 1,
        RELAY_SETTINGS = 123,
        RELAY_PUMP_CH = 2,
        RELAY_REGULATOR_POKOJOWY = 3,
        RELAY_TERMOSTAT_STANDARD_1 = 5,
        RELAY_TERMOSTAT_STANDARD_2 = 6,
        RELAY_CH_TEMP_THRESHOLD = 7,
        RELAY_CH_HYSTERESIS = 8,
        RELAY_CH_CURRENT_TEMP = 10,
        RELAY_CH_ROOM_WARMED = 120,
        RELAY_PUMP_DHW = 11,
        RELAY_DHW_TEMP_THRESHOLD = 12,
        RELAY_DHW_HYSTERESIS = 13,
        RELAY_DHW_SET_TEMP = 14,
        RELAY_DHW_WEEKLY_CONTROL = 18,
        RELAY_DHW_WEEKLY_CONTROL_ON_OFF = 19,
        RELAY_MONDAY = 20,
        RELAY_TUESDAY = 32,
        RELAY_WEDNESDAY = 44,
        RELAY_THURSDAY = 56,
        RELAY_FRIDAY = 68,
        RELAY_SATURDAY = 80,
        RELAY_SUNDAY = 92,
        RELAY_DHW_CURRENT_TEMP = 104,
        RELAY_DHW_TEMP_CORRECTION = 119,
        RELAY_DHW_CURRENT_TURN_ON_TEMP = 153,
        RELAY_PUMP_BUFFER = 105,
        RELAY_BUFFER_SET_TEMP_TOP = 106,
        RELAY_BUFFER_SET_TEMP_BOTTOM = 107,
        RELAY_BUFFER_CURRENT_TEMP_TOP = 108,
        RELAY_BUFFER_CURRENT_TEMP_BOTTOM = 109,
        RELAY_BUFFER_DHW_FUNCTION = 164,
        RELAY_PUMP_FLOOR = 154,
        RELAY_FLOOR_TEMP_THRESHOLD = 155,
        RELAY_FLOOR_MAX_TEMPERATURE = 156,
        RELAY_FLOOR_HYSTERESIS = 157,
        RELAY_FLOOR_SET_SENSOR = 158,
        RELAY_FLOOR_REGULATOR_POKOJOWY = 159,
        RELAY_FLOOR_TERMOSTAT_STANDARD_1 = 160,
        RELAY_FLOOR_TERMOSTAT_STANDARD_2 = 161,
        RELAY_FLOOR_ROOM_WARMED = 162,
        RELAY_FLOOR_CURRENT_TEMP = 163,
        RELAY_PUMP_VALVE = 115,
        RELAY_PUMP_CIRCULATION_PUMP = 116,
        RELAY_CIRCULATION_WORK_TIME = 121,
        RELAY_CIRCULATION_PAUSE_TIME = 122,
        RELAY_WORK_PLAN = 150,
        RELAY_PUMP_ALARM = 117,
        RELAY_PUMP_CONTROLLER_WORK = 118,
        RELAY_PUMP_BOILER_PUMP = 124,
        RELAY_BOILER_PUMP_TEMP_THRESHOLD = 125,
        RELAY_BOILER_PUMP_CURRENT_TEMP = 126,
        RELAY_BOILER_PUMP_HYSTERESIS = 127,
        RELAY_EXCHANGER_CLEANING = 166,
        RELAY_EXCHANGER_CLEANING_WORK_PLAN_MON_SUN = 168,
        RELAY_EXCHANGER_CLEANING_OPERATION_TIME = 171,
    };

    enum Valve
    {
        VALVE_REGISTRATION = 1,
        VALVE_REGISTRATION_CODE = 2,
        VALVE_REGISTRATION_STATUS = 4,
        VALVE_TURN_ON = 5,
        VALVE_VALVE_SET_TEMP_CH = 6,
        VALVE_VALVE_SET_TEMP_FLOOR = 7,
        VALVE_CALIBRATION = 8,
        VALVE_SINGLE_STEP = 9,
        VALVE_MIN_OPENING = 10,
        VALVE_OPENING_TIME = 11,
        VALVE_MEASUREMENT_PAUSE = 12,
        VALVE_VALVE_TYPE = 13,
        VALVE_OPENING_DIRECTION = 14,
        VALVE_MAX_TEMP_FLOOR = 252,
        VALVE_WEATHER_CONTROLL = 15,
        VALVE_WEATHER_CONTROL_ON_OFF = 16,
        VALVE_SET_TEMP_MINUS_20CH = 42,
        VALVE_SET_TEMP_MINUS_10CH = 43,
        VALVE_SET_TEMP_0CH = 44,
        VALVE_SET_TEMP_10CH = 45,
        VALVE_SET_TEMP_MINUS_20FLOOR = 161,
        VALVE_SET_TEMP_MINUS_10FLOOR = 160,
        VALVE_SET_TEMP_0FLOOR = 159,
        VALVE_SET_TEMP_10FLOOR = 158,
        VALVE_ROOM_REGULATOR = 17,
        VALVE_REGULATOR_STANDARD = 41,
        VALVE_ROOM_REG_TEMP_LOWER_CH = 19,
        VALVE_ROOM_REG_TEMP_LOWER_FLOOR = 162,
        VALVE_CLOSE_VALVE_ROOM = 164,
        VALVE_WEEKLY_CONTROL = 47,
        VALVE_WEEKLY_CONTROLL_IS_ON = 167,
        VALVE_MONDAY = 168,
        VALVE_TUESDAY = 180,
        VALVE_WEDNESDAY = 192,
        VALVE_THURSDAY = 204,
        VALVE_FRIDAY = 216,
        VALVE_SATURDAY = 228,
        VALVE_SUNDAY = 240,
        VALVE_PROPOR_COEFF = 22,
        VALVE_BOILER_PROTECTION = 24,
        VALVE_BOILER_PROTECTION_ON_OFF = 25,
        VALVE_MAX_TEMPERATURE = 26,
        VALVE_RETURN_PROTECTION = 27,
        VALVE_RETURN_PROTECTION_ON_OFF = 28,
        VALVE_MIN_RETURN_TEMP = 29,
        VALVE_VALVE_POMP = 30,
        VALVE_VALVE_POMP_TYPE = 31,
        VALVE_SWITCH_ON_TEMPERATURE = 32,
        VALVE_PUMPS_ANTISTOP = 33,
        VALVE_FACTORY_SETTINGS = 34,
        VALVE_REMOVE_VALVE = 35,
        VALVE_VALUE_OPENING = 36,
        VALVE_VALUE_CURRENT = 37,
        VALVE_VALUE_RETURN = 38,
        VALVE_CURRENT_STATE = 39,
        VALVE_ACTIVE_LOCKS = 40,
        VALVE_CORRECTION = 46,
        VALVE_ICON_STATUSES = 157,
        VALVE_DIALOG_VERSION = 165,
        VALVE_VALVE_VERSION = 166,
    };

    struct SStanPrzekaznikow
    {
        bool GRZALKI :1;
        bool POMPA_CO :1;
        bool ZAWOR_OTWORZ :1;
        bool ZAWOR_ZAMKNIJ :1;
        bool RESERVED1 :4;
        bool RESERVED2 :8;

        uint16_t getData()
        {
            return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
            *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
            return (uint16_t*) this;
        }
    };
    static_assert(sizeof(SStanPrzekaznikow)==2,"Unsuported compiller");

    enum TAlarms
    {
        CH_TEMP_TOO_HIGH,
        CH_SENSOR_BROKEN,
        IGNITION_FAILED,
        FEEDER_TEMP_TOO_HIGH,
        DHW_SENSOR_BROKEN,
        THERMAL_PROTECTION_OPEN,
        RETURN_SENSOR_BROKEN,
        BUFFOR_UP_SENSOR_BROKEN,
        BUFFOR_DOWN_SENSOR_BROKEN,
        C1_SENSOR_BROKEN,
        C2_SENSOR_BROKEN,
        GRATE_BLOCKED,
        HEATER_SENSOR_BROKEN,
        VALVE_SENSOR_BROKEN,
        MOSFET_SENSOR_BROKEN,
        MOSFET_TEMP_TOO_HIGH,
        WEATHER_SENSOR_BROKEN,
        FEEDER_SENSOR_BROKEN,
        FIRE_VANISHED,
        INCORRECT_HEATER_CURRENT,
        INCORRECT_FAN_CURRENT,
        FLUE_GAS_SENSOR_BROKEN_ALARM,
    };

    struct SBoilerWarningStates
        {
            bool MISSING_50_HZ :1;
            bool MISSING_VALVE_CONNECTION_1 :1;
            bool MISSING_VALVE_CONNECTION_2 :1;
            bool MISSING_VALVE_CONNECTION_3 :1;
            bool OPEN_THERMAL :1;
            bool MISSING_COMMUNICATION_INTERNET_MODULE :1;
            bool UNKNOWN_INTERNET_MODULE :1;
            bool MISSING_COMMUNICATION_EXHAUST_FAN :1;
            bool WRONG_BOILER_CURVE_PARAMETERS :1;
            bool RESERVED :7;

            uint16_t getData()
            {
                return *((uint16_t*) this);
            }

            void setData(uint16_t data)
            {
                *((uint16_t*) this) = data;
            }

            uint16_t *getPtr()
            {
                return (uint16_t*) this;
            }
        };

    struct SBoilerAlarmStates
    {
        bool CH_TEMP_TOO_HIGH :1;
        bool CH_SENSOR_BROKEN :1;
        bool IGNITION_FAILED :1;
        bool FEEDER_TEMP_TOO_HIGH :1;
        bool THERMAL_PROTECTION_OPEN :1;
        bool BUFFOR_UP_SENSOR_BROKEN :1;
        bool BUFFOR_DOWN_SENSOR_BROKEN :1;
        bool GRATE_BLOCKED :1;
        bool HEATER_SENSOR_BROKEN :1;
        bool MOSFET_SENSOR_BROKEN :1;
        bool MOSFET_TEMP_TOO_HIGH :1;
        bool FEEDER_SENSOR_BROKEN :1;
        bool FIRE_VANISHED :1;
        bool INCORRECT_HEATER_CURRENT :1;
        bool INCORRECT_FAN_CURRENT :1;
        bool FLUE_GAS_SENSOR_BROKEN :1;

        uint16_t getData()
        {
            return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
            *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
            return (uint16_t*) this;
        }
    };

    static_assert(sizeof(SBoilerAlarmStates)==2, "Compiller unsuported");

    struct SVisibilityFlags
    {
        bool FIRING_UP :1;
        bool MANUAL_MODE :1;
        bool DHW_ACTIVE :1;
        bool IS_FIRE :1;
        bool TWO_RELAYS_GRATE :1;
        bool FAN_ERROR :1;
        bool IS_LOCK :1;
        bool IS_HEATING_DEMAND :1;
        bool STOCKER_ENABLED : 1;
        bool GRATE_ENABLED : 1;
        bool BURNING_CURVE_ENABLED : 1;
        bool RESERVED2:5;

        uint16_t getData()
        {
            return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
            *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
            return (uint16_t*) this;
        }
    };

    static_assert(sizeof(SVisibilityFlags)==2, "Compiller unsuported");

    struct SPump1Pump2Pump3AlarmStates
    {
        bool CH_SENSOR_BROKEN_PUMP1 :1;
        bool CH_TEMP_TOO_HIGH_PUMP1 :1;
        bool C1_SENSOR_BROKEN_PUMP1 :1;
        bool C2_SENSOR_BROKEN_PUMP1 :1;
        bool DHW_SENSOR_BROKEN_PUMP1 :1;
        bool CH_SENSOR_BROKEN_PUMP2 :1;
        bool CH_TEMP_TOO_HIGH_PUMP2 :1;
        bool C1_SENSOR_BROKEN_PUMP2 :1;
        bool C2_SENSOR_BROKEN_PUMP2 :1;
        bool DHW_SENSOR_BROKEN_PUMP2 :1;
        bool CH_SENSOR_BROKEN_PUMP3 :1;
        bool CH_TEMP_TOO_HIGH_PUMP3 :1;
        bool C1_SENSOR_BROKEN_PUMP3 :1;
        bool C2_SENSOR_BROKEN_PUMP3 :1;
        bool DHW_SENSOR_BROKEN_PUMP3 :1;
        bool RESERVED :1;

        uint16_t getData()
        {
            return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
            *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
            return (uint16_t*) this;
        }
    };

    static_assert(sizeof(SPump1Pump2Pump3AlarmStates)==2,"Compiller unsuported");

    struct SPump4Pump5AlarmStates
    {
        bool CH_SENSOR_BROKEN_PUMP4 :1;
        bool CH_TEMP_TOO_HIGH_PUMP4 :1;
        bool C1_SENSOR_BROKEN_PUMP4 :1;
        bool C2_SENSOR_BROKEN_PUMP4 :1;
        bool DHW_SENSOR_BROKEN_PUMP4 :1;
        bool CH_SENSOR_BROKEN_PUMP5 :1;
        bool CH_TEMP_TOO_HIGH_PUMP5 :1;
        bool C1_SENSOR_BROKEN_PUMP5 :1;
        bool C2_SENSOR_BROKEN_PUMP5 :1;
        bool DHW_SENSOR_BROKEN_PUMP5 :1;
        bool RESERVED :6;

        uint16_t getData()
        {
            return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
            *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
            return (uint16_t*) this;
        }
    };

    static_assert(sizeof(SPump4Pump5AlarmStates)==2, "Compiller unsuported");


    struct SValve1Valve2AlarmStates
    {
        bool CH_SENSOR_BROKEN_VALVE1 :1;
        bool WEATHER_SENSOR_BROKEN_VALVE1 :1;
        bool VALVE_SENSOR_BROKEN_VALVE1 :1;
        bool RETURN_SENSOR_BROKEN_VALVE1 :1;
        bool DHW_SENSOR_BROKEN_VALVE1 :1;
        bool CH_SENSOR_BROKEN_VALVE2 :1;
        bool WEATHER_SENSOR_BROKEN_VALVE2 :1;
        bool VALVE_SENSOR_BROKEN_VALVE2 :1;
        bool RETURN_SENSOR_BROKEN_VALVE2 :1;
        bool DHW_SENSOR_BROKEN_VALVE2 :1;
        bool RESERVED :6;


        uint16_t getData()
        {
            return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
            *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
            return (uint16_t*) this;
        }
    };

    static_assert(sizeof(SValve1Valve2AlarmStates)==2, "Compiller unsuported");

    struct SAdditionalValve123AlarmStates
    {
        bool CH_SENSOR_BROKEN_ADDITIONAL_VALVE1 :1;
        bool WEATHER_SENSOR_BROKEN_ADDITIONAL_VALVE1 :1;
        bool ADDITIONAL_VALVE_SENSOR_BROKEN_ADDITIONAL_VALVE1 :1;
        bool RETURN_SENSOR_BROKEN_ADDITIONAL_VALVE1 :1;
        bool DHW_SENSOR_BROKEN_ADDITIONAL_VALVE1 :1;
        bool CH_SENSOR_BROKEN_ADDITIONAL_VALVE2 :1;
        bool WEATHER_SENSOR_BROKEN_ADDITIONAL_VALVE2 :1;
        bool ADDITIONAL_VALVE_SENSOR_BROKEN_ADDITIONAL_VALVE2 :1;
        bool RETURN_SENSOR_BROKEN_ADDITIONAL_VALVE2 :1;
        bool DHW_SENSOR_BROKEN_ADDITIONAL_VALVE2 :1;
        bool CH_SENSOR_BROKEN_ADDITIONAL_VALVE3 :1;
        bool WEATHER_SENSOR_BROKEN_ADDITIONAL_VALVE3 :1;
        bool ADDITIONAL_VALVE_SENSOR_BROKEN_ADDITIONAL_VALVE3 :1;
        bool RETURN_SENSOR_BROKEN_ADDITIONAL_VALVE3 :1;
        bool DHW_SENSOR_BROKEN_ADDITIONAL_VALVE3 :1;
        bool RESERVED:1;


        uint16_t getData()
        {
            return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
            *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
            return (uint16_t*) this;
        }
    };

    static_assert(sizeof(SAdditionalValve123AlarmStates)==2,"Compiller unsuported");

    struct SDampingCause
    {
        bool BOILER_WARMED : 1;
        bool EXTERNAL_LOCK : 1;
        bool WORK_PLAN : 1;
        bool BLOCKADE : 1;
        bool CLEANING : 1;
        bool RESERVED1 : 3;
        bool RESERVED2 : 8;

        uint16_t getData()
        {
            return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
            *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
            return (uint16_t*) this;
        }
    };

    static_assert(sizeof(SDampingCause)==2, "Compiller unsuported");

    struct SMessagesStates
    {
        bool ETHERNET_MODULE_COMMUNICATION_ERROR :1;
        bool RESERVED1 :7;
        bool RESERVED2 :8;

        uint16_t getData()
        {
            return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
            *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
            return (uint16_t*) this;
        }
    };

    static_assert(sizeof(SMessagesStates)==2, "Compiller unsuported");

    struct SWersja
    {
        uint8_t liczba1;
        uint8_t liczba2;
        uint8_t liczba3;

        void setData(uint16_t data)
        {
            liczba1 = (data >> 0) & 0x1F;
            liczba2 = (data >> 5) & 0x1F;
            liczba3 = (data >> 10) & 0x3F;
        }

        uint16_t getData()
        {
            return (liczba3 << 10) | (liczba2 << 5) | (liczba1 << 0);
        }
    };

    struct SData
    {
        uint8_t rok;     //wartosc od 0 do 99 (rok 20XX)
        uint8_t miesiac; //numer miesiaca od 1 do 12
        uint8_t dzien;   //dzien miesiaca

        void setData(uint16_t data)
        {
            rok     = (data >> 0) & 0x7F;
            miesiac = (data >> 7) & 0xF;
            dzien   = (data >> 11) & 0x1F;
        }

        uint16_t getData()
        {
            return (dzien << 11) | (miesiac << 7) | (rok << 0);
        }
    };

    struct SValveLocks
    {
        bool TYLKO_POMPA :1;
        bool TYGODNIOWKA :1;
        bool REGULATOR_POKOJOWY :1;
        bool PRZEGRZANIE_PODLOGI :1;
        bool TRYB_LETNI :1;
        bool PRIORYTET_BOILERA :1;
        bool WYLACZENIE_GRZANIA_PODLOGI :1;
        bool ZAMYANIE_PONIZEJ_PROGU :1;
        bool RESERVED :8;

        uint16_t getData()
        {
        return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
        *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
        return (uint16_t*) this;
        }
    };

    struct SGodzina
    {
        uint8_t minuta;
        uint8_t godzina;

        void setData(uint16_t data)
        {
            minuta  = (data >> 0);
            godzina = (data >> 8);
        }

        uint16_t getData()
        {
            return (godzina << 8) | (minuta << 0);
        }
    };

    struct SValveLocksNew
    {
        bool OPERATION_SCHEDULE_IS_ON: 1;
        bool OPERATION_SCHEDULE_IS_WARMED: 1;

        bool ROOM_REGULATOR_IS_ON: 1;
        bool ROOM_REGULATOR_IS_WARMED: 1;

        bool BOILER_MODE_IS_ON: 1;
        bool BOILER_MODE_IS_WARMED :1;

        bool FLOOR_HEATING_IS_ON: 1;
        bool FLOOR_HEATING_IS_WARMED: 1;

        bool FLOOR_OVERHEAT_IS_ON: 1;
        bool FLOOR_OVERHEAT_IS_WARMED: 1;

        bool SUMMER_MODE_IS_ON: 1;
        bool SUMMER_MODE_IS_WARMED: 1;

        bool CLOSING_BELOW_TEMP_TRESHOLD_IS_ON: 1;
        bool CLOSING_BELOW_TEMP_TRESHOLD_IS_WARMED: 1;

        bool RESERVED :2;

        uint16_t getData()
        {
        return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
        *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
        return (uint16_t*) this;
        }
    };

    struct SValveStatuses
    {
        bool ROOM_IS_ON :1;
        bool ROOM_DECREASE:1;
        bool WEATHER_IS_ON:1;
        bool WEATHER_DECREASE :1;
        bool WEEKDAY_IS_ON :1;
        bool WEEKDAY_DECREASE :1;
        bool VALVE_PUMP :1;
        bool RESERVED1 :1;
        bool RESERVED2: 8;

        uint16_t getData()
        {
        return *((uint16_t*) this);
        }

        void setData(uint16_t data)
        {
        *((uint16_t*) this) = data;
        }

        uint16_t *getPtr()
        {
        return (uint16_t*) this;
        }
    };

    struct STwoStateInputs
    {
        bool HALL_1 : 1;
        bool HALL_2 : 1;
        bool HALL_3 : 1;
        bool HALL_4 : 1;
        bool HALL_5 : 1;
        bool THERMAL_CONTROL : 1;
        bool RESERVED1 : 2;
        bool RESERVED2 : 8;

        uint16_t getData() { return *((uint16_t*)this); }

        void setData(uint16_t data) { *((uint16_t*)this) = data; }

        uint16_t* getPtr() { return (uint16_t*)this; }
    };

    struct SHeatDemandBlockList
    {
        bool RELAY1 : 1;
        bool RELAY2 : 1;
        bool RELAY3 : 1;
        bool RELAY4 : 1;
        bool RELAY5 : 1;
        bool RELAY6 : 1;
        bool VALVE1 : 1;
        bool VALVE2 : 1;
        bool REMOTE_VALVE1 : 1;
        bool REMOTE_VALVE2 : 1;
        bool REMOTE_VALVE3 : 1;
        bool RESERVED : 5;

        uint16_t getData() { return *((uint16_t*)this); }

        void setData(uint16_t data) { *((uint16_t*)this) = data; }

        uint16_t* getPtr() { return (uint16_t*)this; }
    };
};


class IDNamespaces
{
public:
    static constexpr ObjectID::NamespaceDesc Relay = {20000,500,6};
    static constexpr ObjectID::NamespaceDesc Valve = {10000,500,5};
    static constexpr ObjectID::NamespaceDesc Zone = {40000,250,0};
    static constexpr ObjectID::NamespaceDesc ServiceMenu = {15000,2500,0};

};

#endif /* ID_H_ */
