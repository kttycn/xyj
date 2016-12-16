// autoload.c

string *autoload;

void clean_up_autoload() { autoload = 0; }

void save_autoload()
{
	object *inv;
	int i, j;
	mixed param;

	inv = all_inventory();
	autoload = allocate(sizeof(inv));
	for(i=0, j=0; i<sizeof(inv); i++) {
		if( !(param = inv[i]->query_autoload()) ) continue;
		autoload[j] = base_name(inv[i]);
		if( stringp(param) ) autoload[j] += ":" + param;
		j++;
	}
	autoload = autoload[0..j-1];
}

void restore_autoload()
{
	int i,count;
	object ob;
	string file, param, err;

	if( !pointerp(autoload) ) return;

	for(i=0; i<sizeof(autoload); i++) {
		if( sscanf(autoload[i], "%s:%s", file, param)!=2 ) {
			file = autoload[i];
			param = 0;
		}
		err = catch(ob = new(file));
		if( err || !ob ||
		    (file[0..2]=="/u/"&&!wizardp(this_object())) ) {
		    //mon 1/20/98
		  write("你觉得似乎失落了什么重要的东西，最好通知一下巫师。\n");
		  log_file("AUTOLOAD", sprintf(
		    "Fail to autoload %s of %s, error %s on %s\n",
		    file, this_object()->query("id"), err, ctime(time())));
	 	  continue;
		}
		export_uid(ob);
		ob->move(this_object());
                count+=ob->wear();
		ob->autoload(param);
	}
// Not sure how count works, it isn't initialized (to be 0?) Dream 8/24/97
//        if (count==0)
/*        {     
           object user,cloth;
           user=this_object();
           if (user->query("gender")=="女性")
           {
              cloth = new("/obj/loginload/skirt.c");
              cloth->move(user);
              cloth->wear();
              cloth = new("/obj/loginload/shoes.c");
	      cloth->move(user);
              cloth->wear();
            }
            else
              cloth = new("/obj/loginload/linen.c");
              cloth->move(user);
              cloth->wear();
        }
*/
	{
		object user,cloth,shoe;
		user=this_object();
		if (user->query("class")=="bonze")
		{
			if (user->query("gender")=="女性")
			{
				cloth = new("/obj/loginload/ni-cloth.c");
				shoe = new("/obj/loginload/ni-xie.c");
			}
			else
			{
				cloth = new("/obj/loginload/seng-cloth.c");
				shoe = new("/obj/loginload/seng-xie.c");
			}
		}
		else
		{
			if (user->query("class")=="taoist")
			{
				if ( user->query("gender")=="女性")
				{
					cloth = new("/obj/loginload/daogu-cloth.c");
					shoe = new("/obj/loginload/dao-xie.c");
				}
				else
				{
					cloth = new("/obj/loginload/dao-cloth.c");
					shoe = new("/obj/loginload/dao-xie.c");
				}
			}
			else
			{
				if ( user->query("gender")=="女性")
				{
					shoe = new("/obj/loginload/female-shoe.c");
					switch (random(8))
					{
						case 1:
					cloth = new("/obj/loginload/female1-cloth.c");
						break;
						case 2:
					cloth = new("/obj/loginload/female2-cloth.c");
						break;
						case 3:
					cloth = new("/obj/loginload/female3-cloth.c");
						break;
						case 4:
					cloth = new("/obj/loginload/female4-cloth.c");
						break;
						case 5:
					cloth = new("/obj/loginload/female5-cloth.c");
						break;
						case 6:
					cloth = new("/obj/loginload/female6-cloth.c");
						break;
						case 7:
					cloth = new("/obj/loginload/female7-cloth.c");
						break;
						default:
					cloth = new("/obj/loginload/female8-cloth.c");
					}
				}
				else
				{
					shoe = new("/obj/loginload/male-shoe.c");
					switch (random(8))
					{
						case 1:
					cloth = new("/obj/loginload/male1-cloth.c");
						break;
						case 2:
					cloth = new("/obj/loginload/male2-cloth.c");
						break;
						case 3:
					cloth = new("/obj/loginload/male3-cloth.c");
						break;
						case 4:
					cloth = new("/obj/loginload/male4-cloth.c");
						break;
						case 5:
					cloth = new("/obj/loginload/male5-cloth.c");
						break;
						case 6:
					cloth = new("/obj/loginload/male6-cloth.c");
						break;
						case 7:
					cloth = new("/obj/loginload/male7-cloth.c");
						break;
						default:
					cloth = new("/obj/loginload/male8-cloth.c");
					}
				}
			}
		}
		cloth->move(user);
		cloth->wear();
		shoe->move(user);
		shoe->wear();
	}

	clean_up_autoload();		// To save memory.
}
