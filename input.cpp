template<typename Value>
void circularShift(Value &value) {
    const bool firstSet = (value & 0b1u);
    value >>= 1;
    if (firstSet) {
        value |= static_cast<Value>(0b1u) << (sizeof(Value)*8-1);
    }
}

uint32_t value1 = 0xabcd0123u;
uint16_t value2 = 0x4545u;

void setup() {
    Serial.begin(115200);
    while (!Serial) {}
}

void loop() {
    Serial.println(value1, BIN);    
    Serial.println(value2, BIN);    
    circularShift(value1);
    circularShift(value2);
    delay(1000);
}
