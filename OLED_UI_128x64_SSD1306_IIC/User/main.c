#include "OLED_UI.h"
#include "OLED_UI_MenuData.h"
#include "MyRTC.h"
/*Ŀǰ����Ϊ���԰棬���������Ż�����*/
/*���߷�ʽ��
scl pb8 
sda pb9
res pb5
dc  pb6
cs  pb7
ȷ�ϰ��� pb12
ȡ������ pb13
�ϰ���   pb14
�°���   pb15
 ������a pa8
 ������b pa9
 ���������� pb12
*/

int main(){
	MyRTC_Init();
	OLED_UI_Init(&ColckMenuPage);

	while(1){

		OLED_UI_MainLoop();
	
	}
}

//�жϺ���
void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		OLED_UI_InterruptHandler();
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}
