// git add

static int valIndex = 0, valArrays[15][8] = {0};

unsigned short servo_alarm_wave_filter(unsigned short almFlag) {
	volatile unsigned short tempVal = almFlag;
	unsigned short tempValArrays[8] = {0}, retVal = 0;
	for (int i = 0; i < 8; i++) {
		// 赋值
		valArrays[valIndex][i] = (tempVal << i) & 1;
	}
	valIndex = (valIndex + 1) % 15;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 15; j++) {
			// 统计15次的电平变化
			tempValArrays[i] += valArrays[j][i];
		}
		retVal |= (((tempValArrays[i] > 9) ? 1 : 0) << i);
	}
	return retVal;
}
