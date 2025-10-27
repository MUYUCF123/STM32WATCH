#include "OLED_UI_MenuData.h"
#include "OLED_UI.h"
#include "MyRTC.h"
/*���ļ����ڴ�Ų˵����ݡ�ʵ���ϲ˵����ݿ��Դ�����κεط�������ڴ˴���Ϊ�˹淶�����ģ�黯*/

// ColorMode ��һ����OLED_UI���ж����bool���ͱ��������ڿ���OLED��ʾ����ɫģʽ�� DARKMODE Ϊ��ɫģʽ�� LIGHTMOOD Ϊǳɫģʽ�����ｫ��������Ϊ�˴�����ѡ��˵��
extern bool ColorMode;
extern bool OLED_UI_ShowFps;
// OLED_UI_Brightness ��һ����OLED_UI���ж����int16_t���ͱ��������ڿ���OLED��ʾ�����ȡ����ｫ��������Ϊ�˴����������ȵĻ��������ڣ���Χ0-255��
extern int16_t OLED_UI_Brightness;
float testfloatnum = 0.5;
int32_t testintnum = 1;
#define SPEED 10

//���ڵĹرջص�
void TimeWindowClose(void){
	MyRTC_SetTime();
}

//���ڴ��ڵĽṹ��
MenuWindow SetBrightnessWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "��Ļ������Ļ����",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_16 = &OLED_UI_Brightness,				//��ʾ�ı�����ַ
	.Prob_DataStep = 5,								//����
	.Prob_MinData = 5,									//��Сֵ
	.Prob_MaxData = 255, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
	.General_WindowCloseCallback =NULL
};
MenuWindow SetYearWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "��",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_32 = &MyRTC_Time[0],				//��ʾ�ı�����ַ
	.Prob_DataStep = 1,								//����
	.Prob_MinData = 1024,									//��Сֵ
	.Prob_MaxData = 4096, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
	.General_WindowCloseCallback = TimeWindowClose
};
MenuWindow SetMonWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "��",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_32 = &MyRTC_Time[1],				//��ʾ�ı�����ַ
	.Prob_DataStep = 1,								//����
	.Prob_MinData = 1,									//��Сֵ
	.Prob_MaxData = 12, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
	.General_WindowCloseCallback = TimeWindowClose
};
MenuWindow SetDayWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "��",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_32 = &MyRTC_Time[2],				//��ʾ�ı�����ַ
	.Prob_DataStep = 1,								//����
	.Prob_MinData = 1,									//��Сֵ
	.Prob_MaxData = 31, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
	.General_WindowCloseCallback = TimeWindowClose
};
MenuWindow SetHourWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "ʱ",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_32 = &MyRTC_Time[3],				//��ʾ�ı�����ַ
	.Prob_DataStep = 1,								//����
	.Prob_MinData = 1,									//��Сֵ
	.Prob_MaxData = 24, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
	.General_WindowCloseCallback = TimeWindowClose
};
MenuWindow SetMinWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "��",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_32 = &MyRTC_Time[4],				//��ʾ�ı�����ַ
	.Prob_DataStep = 1,								//����
	.Prob_MinData = 0,									//��Сֵ
	.Prob_MaxData = 60, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
	.General_WindowCloseCallback = TimeWindowClose
};
MenuWindow SetSecWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.Text_String = "��",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 4,							//����������ľ���
	.Text_FontTopDistance = 3,							//������붥���ľ���
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Prob_Data_Int_32 = &MyRTC_Time[5],				//��ʾ�ı�����ַ
	.Prob_DataStep = 1,								//����
	.Prob_MinData = 0,									//��Сֵ
	.Prob_MaxData = 60, 								//���ֵ
	.Prob_BottomDistance = 3,							//�ײ����
	.Prob_LineHeight = 8,								//�������߶�
	.Prob_SideDistance = 4,								//�߾�
	.General_WindowCloseCallback = TimeWindowClose
};
/**
 * @brief ������ʾ���ȴ���
 */
void BrightnessWindow(void){
	OLED_UI_CreateWindow(&SetBrightnessWindow);
}
void YearWindow(void){
	OLED_UI_CreateWindow(&SetYearWindow);
}
void MonWindow(void){
	OLED_UI_CreateWindow(&SetMonWindow);
}
void DayWindow(void){
	OLED_UI_CreateWindow(&SetDayWindow);
}
void HourWindow(void){
	OLED_UI_CreateWindow(&SetHourWindow);
}
void MinWindow(void){
	OLED_UI_CreateWindow(&SetMinWindow);
}
void SecWindow(void){
	OLED_UI_CreateWindow(&SetSecWindow);
}
//���ڴ��ڵĽṹ��
MenuWindow NullWindow = {
	.General_Width = 80,								//���ڿ��
	.General_Height = 28, 							//���ڸ߶�
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��
	.General_WindowCloseCallback =NULL
};
/**
 * @brief ������ʾ���ȴ���
 */
void EmptyWindow(void){
	OLED_UI_CreateWindow(&NullWindow);
}
//���ڴ��ڵĽṹ��
MenuWindow TextWindow = {
	.General_Width = 75,								//���ڿ��
	.General_Height = 18, 							//���ڸ߶�
	.General_WindowType = WINDOW_ROUNDRECTANGLE, 	//��������
	.General_ContinueTime = 4.0,						//���ڳ���ʱ��

	.Text_String = "����text",					//���ڱ���
	.Text_FontSize = OLED_UI_FONT_12,				//�ָ�
	.Text_FontSideDistance = 8,							//����������ľ���
	.Text_FontTopDistance = 2,							//������붥���ľ���
	.General_WindowCloseCallback =NULL

};

//��LOGO�ƶ��Ľṹ��
OLED_ChangePoint LogoMove;
//��LOGO�����ƶ��Ľṹ��
OLED_ChangePoint LogoTextMove;
//welcome�����ƶ��Ľṹ��
OLED_ChangePoint WelcomeTextMove;

extern OLED_ChangePoint OLED_UI_PageStartPoint ;

void ClockAuxFunc(void){
  MyRTC_ReadTime();
	OLED_Printf(0,0,OLED_6X8_HALF ,"%d-%d-%d",MyRTC_Time[0],MyRTC_Time[1],MyRTC_Time[2]);
//	OLED_Printf(0,16,OLED_12x24_FULL,"%02d:",MyRTC_Time[3]);
//	OLED_Printf(30,20,OLED_12x24_FULL,"%02d:",MyRTC_Time[4]);
//	OLED_Printf(54,24,OLED_12x24_FULL,"%02d:",MyRTC_Time[5]);
	OLED_Printf(0,16,OLED_12x24_HALF,"%02d:%02d",MyRTC_Time[3],MyRTC_Time[4]);
	OLED_Printf(60,24,OLED_8X16_HALF,":%02d",MyRTC_Time[5]);
	
}

//���ò˵���ĸ�����ʾ����
void SettingAuxFunc(void){
	//�ڹ涨λ����ʾLOGO
	if(fabs(OLED_UI_PageStartPoint.CurrentPoint.X - OLED_UI_PageStartPoint.TargetPoint.X) < 4){
		LogoMove.TargetPoint.X = 0;
		LogoMove.TargetPoint.Y = 0;
	}
	//��LOGOTEXT�ƶ�����Ļ�Ҳ࿴�����ĵط�
	LogoTextMove.TargetPoint.X = 129;
	LogoTextMove.TargetPoint.Y = 0;
	//��Welcome�����ƶ�����Ļ�ײ��������ĵط�
	WelcomeTextMove.TargetPoint.X = 128;
	WelcomeTextMove.TargetPoint.Y = 0;
	ChangePoint(&LogoMove);
	OLED_ShowImageArea(LogoMove.CurrentPoint.X,LogoMove.CurrentPoint.Y,32,64,0,0,128,128,OLED_UI_SettingsLogo);
	ChangePoint(&LogoTextMove);
	OLED_ShowImageArea(LogoTextMove.CurrentPoint.X,LogoTextMove.CurrentPoint.Y,26,64,0,0,128,128,OLED_UI_LOGOTEXT64);
	ChangePoint(&WelcomeTextMove);
	OLED_ShowImageArea(WelcomeTextMove.CurrentPoint.X,WelcomeTextMove.CurrentPoint.Y,16,64,0,0,128,128,OLED_UI_LOGOGithub);
}
//����ʱ��ĸ�����ʾ����
void SettingTimeAuxFunc(void){
	//��LOGO�ƶ�����Ļ�Ϸ��������ĵط�
	LogoMove.TargetPoint.X = 0;
	LogoMove.TargetPoint.Y = -80;
	ChangePoint(&LogoMove);
    OLED_ShowImageArea(LogoMove.CurrentPoint.X,LogoMove.CurrentPoint.Y,32,64,0,0,128,128,OLED_UI_SettingsLogo);
	//����Ļ�Ҳ���ʾLOGO����
	if(fabs(OLED_UI_PageStartPoint.CurrentPoint.X - OLED_UI_PageStartPoint.TargetPoint.X) < 4){
		LogoTextMove.TargetPoint.X = 102;
		LogoTextMove.TargetPoint.Y = 0;
	}
	ChangePoint(&LogoTextMove);
	OLED_ShowImageArea(LogoTextMove.CurrentPoint.X,LogoTextMove.CurrentPoint.Y,26,64,0,0,128,128,OLED_UI_LOGOTIME);
}
//���ڲ˵��ĸ�����ʾ����
void AboutThisDeviceAuxFunc(void){
	//��LOGO�ƶ�����Ļ�Ϸ��������ĵط�
	LogoMove.TargetPoint.X = 0;
	LogoMove.TargetPoint.Y = -80;
	ChangePoint(&LogoMove);
    OLED_ShowImageArea(LogoMove.CurrentPoint.X,LogoMove.CurrentPoint.Y,32,64,0,0,128,128,OLED_UI_SettingsLogo);
	//����Ļ�Ҳ���ʾLOGO����
	if(fabs(OLED_UI_PageStartPoint.CurrentPoint.X - OLED_UI_PageStartPoint.TargetPoint.X) < 4){
		LogoTextMove.TargetPoint.X = 102;
		LogoTextMove.TargetPoint.Y = 0;
	}
	ChangePoint(&LogoTextMove);
	OLED_ShowImageArea(LogoTextMove.CurrentPoint.X,LogoTextMove.CurrentPoint.Y,26,64,0,0,128,128,OLED_UI_LOGOTEXT64);
}
//����OLED UI�ĸ�����ʾ����
void AboutOLED_UIAuxFunc(void){
	//��LOGO�ƶ�����Ļ�Ϸ��������ĵط�
	LogoMove.TargetPoint.X = 0;
	LogoMove.TargetPoint.Y = -80;
	ChangePoint(&LogoMove);
	OLED_ShowImageArea(LogoMove.CurrentPoint.X,LogoMove.CurrentPoint.Y,32,64,0,0,128,128,OLED_UI_SettingsLogo);
	//����Ļ�Ҳ���ʾWelcome����
	if(fabs(OLED_UI_PageStartPoint.CurrentPoint.X - OLED_UI_PageStartPoint.TargetPoint.X) < 4){
		WelcomeTextMove.TargetPoint.X = 110;
		WelcomeTextMove.TargetPoint.Y = 0;
	}
	ChangePoint(&WelcomeTextMove);
	OLED_ShowImageArea(WelcomeTextMove.CurrentPoint.X,WelcomeTextMove.CurrentPoint.Y,16,64,0,0,128,128,OLED_UI_LOGOGithub);

}
//���˵��ĸ�����ʾ����
void MainAuxFunc(void){
	//����ʾ
	LogoMove.TargetPoint.X = -200;
	LogoMove.TargetPoint.Y = 0;
	LogoMove.CurrentPoint.X = -200;
	LogoMove.CurrentPoint.Y = 0;

	LogoTextMove.TargetPoint.X = 129;
	LogoTextMove.TargetPoint.Y = 0;
	LogoTextMove.CurrentPoint.X = 129;
	LogoTextMove.CurrentPoint.Y = 0;
	
	WelcomeTextMove.TargetPoint.X = 128;
	WelcomeTextMove.TargetPoint.Y = 0;
	WelcomeTextMove.CurrentPoint.X = 128;
	WelcomeTextMove.CurrentPoint.Y = 0;
}
//��ҳʱ��ҳ��Ĳ˵���
MenuItem ColckMenuItems[] = {
	//ȫ������ΪNULL��ֻ�������Ӽ�
	{.General_item_text = NULL ,.General_callback = NULL,.General_SubMenuPage = &MainMenuPage,.Tiles_Icon = NULL,.List_BoolRadioBox = NULL},

};

//���˵��Ĳ˵���
MenuItem MainMenuItems[] = {

	{.General_item_text = "Settings",.General_callback = NULL,.General_SubMenuPage = &SettingsMenuPage,.Tiles_Icon = Image_setings},
	{.General_item_text = "WeChat",.General_callback = NULL,.General_SubMenuPage = NULL,.Tiles_Icon = Image_wechat},
	{.General_item_text = "Alipay",.General_callback = NULL,.General_SubMenuPage = NULL,.Tiles_Icon = Image_alipay},
	{.General_item_text = "������ Calc ���ı����� LongText",.General_callback = NULL,.General_SubMenuPage = NULL,.Tiles_Icon = Image_calc},
	{.General_item_text = "Night",.General_callback = NULL,.General_SubMenuPage = NULL,.Tiles_Icon = Image_night},
	{.General_item_text = "More",.General_callback = NULL,.General_SubMenuPage = NULL,.Tiles_Icon = Image_more},
	{.General_item_text = "Return",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.Tiles_Icon = Image_more},
	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/
//void BackEventMenuItem(void)
};
//���ò˵�����������
MenuItem SettingsMenuItems[] = {
	{.General_item_text = "����",.General_callback = BrightnessWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "�ڰ�ģʽ",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = &ColorMode},
	{.General_item_text = "��ʾ֡��",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = &OLED_UI_ShowFps},
	{.General_item_text = "���豸",.General_callback = NULL,.General_SubMenuPage = &AboutThisDeviceMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "����ʱ��",.General_callback = NULL,.General_SubMenuPage = &SettingTimeMenuPage,.List_BoolRadioBox = NULL},
	{.General_item_text = "[����]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/
};

MenuItem SettingTimeItems[] = {
	{.General_item_text = "������",.General_callback = YearWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "������",.General_callback = MonWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "������",.General_callback = DayWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "����ʱ",.General_callback = HourWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "���÷�",.General_callback = MinWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "������",.General_callback = SecWindow,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "[����]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/
};

MenuItem AboutThisDeviceMenuItems[] = {
	{.General_item_text = "-[MCU:]",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " STM32F103",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " RAM:20KB",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " ROM:64KB",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "-[Screen:]",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " SSD1306 128x64 OLED",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "-[CP:]",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = " SoftWare SPI",.General_callback = NULL,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},
	{.General_item_text = "[����]",.General_callback = OLED_UI_Back,.General_SubMenuPage = NULL,.List_BoolRadioBox = NULL},

	{.General_item_text = NULL},/*���һ���General_item_text��ΪNULL����ʾ����Ϊ�ָ���*/
};


MenuPage ColckMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //�������Ϊ����
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &MainMenuPage,		 //�������Ǹ��˵������Ը��˵�ΪNULL
	.General_LineSpace = 0,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_ShowAuxiliaryFunction = ClockAuxFunc,		 //��ʾ��������
	.General_MenuItems = ColckMenuItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {0, 0, 0, 0},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = false,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 0,                        //�б���ʼ��X����
	.List_StartPointY = 0,                        //�б���ʼ��Y����
};

MenuPage MainMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_TILES,  		 //�˵�����Ϊ��������
	.General_CursorStyle = NOT_SHOW,			 //�������
	.General_FontSize = OLED_UI_FONT_16,			//�ָ�
	.General_ParentMenuPage = &ColckMenuPage,		//���˵�Ϊʱ��ҳ��		
	.General_LineSpace = 5,						//������� ��λ�����أ����ڴ������Ͳ˵�����ֵ��ʾÿ������֮��ļ�࣬�����б����Ͳ˵�����ֵ��ʾ�м�ࣩ
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽ
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_ShowAuxiliaryFunction = MainAuxFunc,		 //��ʾ��������
	.General_MenuItems = MainMenuItems,			//�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.Tiles_ScreenHeight = 64,					//��Ļ�߶�
	.Tiles_ScreenWidth = 128,						//��Ļ���
	.Tiles_TileWidth = 32,						 //�������
	.Tiles_TileHeight = 32,						 //�����߶�
};


MenuPage SettingsMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_ROUNDRECTANGLE,	 //�������Ϊ����
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &MainMenuPage,		 //���˵�Ϊ���˵�
	.General_LineSpace = 4,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_ShowAuxiliaryFunction = SettingAuxFunc,		 //��ʾ��������
	.General_MenuItems = SettingsMenuItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {32, 0, 95, 64},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = true,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 4,                        //�б���ʼ��X����
	.List_StartPointY = 2,                        //�б���ʼ��Y����
};
MenuPage SettingTimeMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_BLOCK,	 //�������ΪԲ�Ǿ���
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &SettingsMenuPage,		 //���˵�Ϊ���˵�
	.General_LineSpace = 4,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_ShowAuxiliaryFunction = SettingTimeAuxFunc,		 //��ʾ��������
	.General_MenuItems = SettingTimeItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {0, 0, 100, 64},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = true,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 4,                        //�б���ʼ��X����
	.List_StartPointY = 2,                        //�б���ʼ��Y����

};
MenuPage AboutThisDeviceMenuPage = {
	//ͨ�����ԣ�����
	.General_MenuType = MENU_TYPE_LIST,  		 //�˵�����Ϊ�б�����
	.General_CursorStyle = REVERSE_BLOCK,	 //�������ΪԲ�Ǿ���
	.General_FontSize = OLED_UI_FONT_12,			//�ָ�
	.General_ParentMenuPage = &SettingsMenuPage,		 //���˵�Ϊ���˵�
	.General_LineSpace = 4,						//�м�� ��λ������
	.General_MoveStyle = UNLINEAR,				//�ƶ���ʽΪ���������߶���
	.General_MovingSpeed = SPEED,					//�����ƶ��ٶ�(��ֵ����ʵ��Ч������)
	.General_ShowAuxiliaryFunction = AboutThisDeviceAuxFunc,		 //��ʾ��������
	.General_MenuItems = AboutThisDeviceMenuItems,		 //�˵�����������

	//�������ԣ�����.General_MenuType������ѡ��
	.List_MenuArea = {0, 0, 100, 64},			 //�б���ʾ����
	.List_IfDrawFrame = false,					 //�Ƿ���ʾ�߿�
	.List_IfDrawLinePerfix = false,				 //�Ƿ���ʾ��ǰ׺
	.List_StartPointX = 4,                        //�б���ʼ��X����
	.List_StartPointY = 2,                        //�б���ʼ��Y����

};



