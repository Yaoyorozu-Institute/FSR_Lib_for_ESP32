# FSR_Lib_for_ESP32
ESP32を用いて、感圧抵抗素子（FSR）から力（単位：gf）を読み取るライブラリです．
データシートに示されていたグラフを指数関数近似しているため，正確な値は読み取れていません．
また，このライブラリでは、[FSR402](https://akizukidenshi.com/catalog/g/gP-04002/)の公式計測データを元にしています．それ以外のFSRでは使えない可能性がありますので，ご注意ください．

### 追加される関数：
#### FSR::FSR(double R_kOhm, double V_milliVolt, uint8_t DIN)
使用するFSRを定義します．R_kOhmはプルアップ抵抗の値を（単位：kΩ），V_milliVoltはプルアップ抵抗及びFSRに接続するVCCの値を（単位：mV），DINはFSR抵抗値を読み取るGPIOピンを示しています．

#### void FSR::Calibration(void)
指定されたFSRをキャリブレーションします．実行された際におけるInputの電圧を基準に設定します．

#### double FSR::Force(void)
指定されたFSRにかかっている力を読み取ります．
