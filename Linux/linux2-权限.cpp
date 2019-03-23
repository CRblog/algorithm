权限：
    多用户操作系统：
		操作权限分类：管理员用户 root ，普通用户
文件权限:
        文件操作对用户的分类：
            文件所有者    文件所属组   其他用户
				u(user)               g(group)           o(other)
        用户对文件操作的分类
            可读      可写      可执行
			  r         w          x
		d    rwx rwx r-x
        权限的存储方式：
				二进制位图
			111 111 101
			7    7   5
        计算权限
        可读可写：可读：可读
        110 100 100
 文件创建时给的权限是664
文件权限的常见命令：
	umask: 查看/设置文件的默认权限掩码
		权限掩码：设置文件的默认创建权限
		实际权限： 给定权限 & (~权限掩码)
		-S(大写)     u=rwx,g=rwx,o=rx
 	chmod 修改文件的权限
		chmod 644 file   通过八进制修改
		chmod o+x        针对用户操作进行修改
		chmod u+r
		chmod g-w
    粘滞位：
		chmod +t
    chown   修改文件所有者
		chown username filename
    chgrp   修改文件所属组
    

		
