#include <ansi.h>

inherit F_DBASE;

int num;

string *families = ({
  "��ѩɽ",
  "����ɽ���Ƕ�",
  "�����¹�",
  "�Ϻ�����ɽ",
  "���޵ظ�",
  "��˿����",
  "������",
  "��������",
  "�ݿ�ɽ�޵׶�",
  "������ׯ��",
  "���ɻ��ƶ�",
  "��ɽ����",
  "��ԯ��Ĺ",
  "������ʥ��",
  "��˳�",
  "��������",
  "���ƻʹ�",
  "ϙ�ǻʹ�",

});

mapping family_masters=([
        "����ɽ���Ƕ�":"��������(Master puti)",
        "�Ϻ�����ɽ":"��������(Guanyin pusa)",
        "������":"�׷�����(Baifa laoren)",
        "������ׯ��":"��Ԫ����(Zhenyuan daxian)",
        "���޵ظ�":"�ز�����(Dizang pusa)",
        "�����¹�":"����ĸ(Xi wangmu)",
        "��������":"��������(Ao guang)",
        "��ѩɽ":"��������(Dapeng mingwang)",
        "�ݿ�ɽ�޵׶�":"����(Yushu jing)",
        "��˿��":"��ϼ����(Zixia xianzi)",
        "���ƶ�":"�Ʒɻ�(Huang feihu)",
        "��ɽ����":"��ɽ��ʥ(Jian sheng)",
        "��ԯ��Ĺ":"槼�(Da ji)",
        "��˳�":"��˹���(Feng huang)",
        "��������":"��ʥ��ʦ������(Guoshiwang pusa)",
        "������ʥ��":"������(Kongwu dadi)",
        "���ƻʹ�":"��̫��(Tang taizhong)",
        "ϙ�ǻʹ�":" ϙ�ǹ���(Guo wang)",
//        "����":"�񻪿���(Yuhua junzhu)",
]);


string *feizei=({
        "fei-putuo",
        "fei-moon",
        "fei-wzg",
        "fei-shushan",
        "fei-hyd",
        "fei-fangcun",
        "fei-hell",
        "fei-jjf",
        "fei-pansi",
        "fei-dragon",
        "fei-xueshan",
        "fei-wudidong",
        "fei-gumu",
        "fei-phoenix",
        "fei-xuyi",
        "fei-wusheng",
        });

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str, smp, where;

        smp  = "������ɽ֮��";                 
        k = random(sizeof(families));
        num = random(sizeof(feizei));

	if (sizeof(users())<20) return;

        newob = new(__DIR__+feizei[num]);
        newob->set("target",families[k]);
        where = newob->invocation();

        switch(families[k])
        {
                case "����ɽ���Ƕ�":
                        newob->carry_object(__DIR__"obj/stick");
                        break;
                case "�����¹�":
                        newob->carry_object(__DIR__"obj/whip");
                        break;
                case "���޵ظ�":
                        newob->carry_object(__DIR__"obj/whip");
                        break;
                case "�ݿ�ɽ�޵׶�":
                        newob->carry_object(__DIR__"obj/blade");
                        break;
                case "������":
                        newob->carry_object(__DIR__"obj/axe");
                        break;
                case "���ɻ��ƶ�":
                        newob->carry_object(__DIR__"obj/spear");
                        break;
                case "��ѩɽ":
                        newob->carry_object(__DIR__"obj/qin");
                        break;
                case "������ׯ��":
                        newob->carry_object(__DIR__"obj/staff");
                        break;
                case "�Ϻ�����ɽ":
                        newob->carry_object(__DIR__"obj/staff");
                        break;
                case "��������":
                        newob->carry_object(__DIR__"obj/fork");
                        break;
                case "��˿��":
                        newob->carry_object(__DIR__"obj/whip");
                        break;
                case "��ɽ����":
                        newob->carry_object(__DIR__"obj/sword");
                        break;
                case "��ԯ��Ĺ":
                        newob->carry_object(__DIR__"obj/needle");
                        break;
                case "������ʥ��":
                        newob->carry_object(__DIR__"obj/sword");
                        break;
                case "��˳�":
                        newob->carry_object(__DIR__"obj/blade");
                        break;
                case "������ʥ��":
                        newob->carry_object(__DIR__"obj/sword");
                        break;
                case "���ƻʹ�":
                        newob->carry_object(__DIR__"obj/mace");
                        smp = "���ƹ���";
                        break;
                case "ϙ�ǻʹ�":
                        newob->carry_object(__DIR__"obj/mace");
                        smp = "��������";
                        break;
                

        }
        message("channel:rumor",HIG"��" + HIR + "����ͨ����" + HIG + "��" + HIW +
                         family_masters(families[k]) + HIG +
                         "����ҹһ�����������" + smp +
                         "�������Ӵ���" + where + "һ��,ɱ���⡣\n"NOR,
                         users());
}

string feizei_num()
{
        return feizei[num];
}
