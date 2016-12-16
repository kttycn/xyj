
void  readallfile(string dir,string *files);
int main(object me)
{
    
		readallfile("/d1/",get_dir("/d1/")); 
		write(" now  is ok \n");	
    return 1;
}
void  readallfile(string dir,string *files)
{
		string roommsg,s1,l1,repeat;
		string file,long;
		long="";
		repeat="";
		reset_eval_cost();
	    for(int i=0;i<sizeof(files);i++)
    {
        file=dir+files[i];
       
        if(file_size(file)==-2)
        {
        	if(files[i]=="obj"||files[i]=="npc")continue;
        	readallfile(file+"/",get_dir(file+"/"));        	
        	}
      else{
        roommsg=read_file(file);
        if(sscanf(roommsg,"%*s\"short\"%*s\"%s\"",s1)!=3)continue;
  
       if( sscanf(roommsg,"%*sLONG%sLONG",l1)!=2)       
       	sscanf(roommsg,"%*s\"long\"%*s\"%s\"",l1);
       	if(repeat==l1)continue; ////remove repeat room 
       	else repeat=l1;
       if(sizeof(s1+l1)>50)  //去掉描述过短的房间，一般都是没写完的
        long=long+s1+l1+"\n";
			}
    }
 write_file( "alllong", long );
	// else write(dir+" now  is empty \n");	
	}
