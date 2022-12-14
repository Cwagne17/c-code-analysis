/**
 * In the rsbac_acl_sys_group function a buffer overflow vulnerability is present.
 * The function checks that the maxnum is less then or equal to zero but in the case
 * where !arg.get_group_members.group evaluates to true then maxnum can be any value.
 * This would then cause vmalloc to write to much to memory allowing for a buffer overflow attack to take place.
*/

// This example was taken from a security module for linux. This code runs in the kernel context:
int rsbac_acl_sys_group( enum rsbac_acl_group_syscall_type_t call, union rsbac_acl_group_syscall_arg_t arg){
    switch(call) {
        case ACLGS_get_group_members:
            if ((arg.get_group_members.maxnum<=0)|| !arg.get_group_members.group) {
                rsbac_uid_t * user_array;
                rsbac_time_t * ttl_array;
                user_array = vmalloc(sizeof(*user_array) * arg.get_group_members.maxnum);
                if (!user_array)
                    return -RSBAC_ENOMEM;
                
                ttl_array = vmalloc(sizeof(*ttl_array) * arg.get_group_members.maxnum);
                if(!ttl_array){
                    vfree(user_array);
                    return -RSBAC_ENOMEM;
                }
                err = rsbac_acl_get_group_members(
                            arg.get_group_members.group,
                            user_array, ttl_array,
                            arg.get_group_members.max,
                            num
                        );
            //...
            }
        //...
    }
    //...
}