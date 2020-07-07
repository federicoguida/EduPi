int convertPin(int Pin);
void ledRGB(struct ast *pin, struct ast *channel);
void setOutPin(struct ast *pin, struct ast *mode);
struct ast *button(struct ast *pin);

void lcd_init(void);
void lcd_byte(int bits, int mode);
void lcd_toggle_enable(int bits);

void sendIntegerLcd(struct ast *integer);
void sendRealLcd(struct ast *real);
void sendStringLcd(struct ast *string);
void lcdLoc(struct ast *line);
void clrLcd(void);
