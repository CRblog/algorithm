struct task_struct {
  1258   volatile long state;  /* -1 unrunnable, 0 runnable, >0 stopped */
  1259   void *stack;
  1260   atomic_t usage;
  1261   unsigned int flags; /* per process flags, defined below */
  1262   unsigned int ptrace;
  1263
  1264 #ifdef CONFIG_SMP
  1265   struct llist_node wake_entry;
  1266   int on_cpu;
  1267   struct task_struct *last_wakee;
  1268   unsigned long wakee_flips;
  1269   unsigned long wakee_flip_decay_ts;
  1270
  1271   int wake_cpu;
  1272 #endif
  1273   int on_rq;
  1274
  1275   int prio, static_prio, normal_prio;
  1276   unsigned int rt_priority;
  1277   const struct sched_class *sched_class;
  1278   struct sched_entity se;
  1279   struct sched_rt_entity rt;
  1280 #ifdef CONFIG_CGROUP_SCHED
  1281   struct task_group *sched_task_group;
  1282 #endif
  1283 #ifdef CONFIG_PREEMPT_NOTIFIERS
  1284   /* list of struct preempt_notifier: */
  1285   struct hlist_head preempt_notifiers;
  1286 #endif
  1287
  1288   /*
  1289    * fpu_counter contains the number of consecutive context switches
  1290    * that the FPU is used. If this is over a threshold, the lazy fpu
  1291    * saving becomes unlazy to save the trap. This is an unsigned char
  1292    * so that after 256 times the counter wraps and the behavior turns
  1293    * lazy again; this to deal with bursty apps that only use FPU for
  1294    * a short time
  1295    */
  1296   unsigned char fpu_counter;
  1297 #ifdef CONFIG_BLK_DEV_IO_TRACE
  1298   unsigned int btrace_seq;
  1299 #endif
  1300
  1301   unsigned int policy;
  1302   int nr_cpus_allowed;
  1303   cpumask_t cpus_allowed;
  1304
  1305 #ifdef CONFIG_PREEMPT_RCU
  1306   int rcu_read_lock_nesting;
  1307   char rcu_read_unlock_special;
  1308   struct list_head rcu_node_entry;
  1309 #endif /* #ifdef CONFIG_PREEMPT_RCU */
  1310 #ifdef CONFIG_TREE_PREEMPT_RCU
  1311   struct rcu_node *rcu_blocked_node;
  1312 #endif /* #ifdef CONFIG_TREE_PREEMPT_RCU */
  1313 #ifdef CONFIG_RCU_BOOST
  1314   struct rt_mutex *rcu_boost_mutex;
  1315 #endif /* #ifdef CONFIG_RCU_BOOST */
  1316
  1317 #ifdef CONFIG_SCHED_INFO
  1318   struct sched_info sched_info;
  1319 #endif
  1320
  1321   struct list_head tasks;
  1322 #ifdef CONFIG_SMP
  1323   struct plist_node pushable_tasks;
  1324 #endif
  1325
  1326   struct mm_struct *mm, *active_mm;
  1327 #ifdef CONFIG_COMPAT_BRK
  1328   unsigned brk_randomized:1;
  1329 #endif
  1330 #if defined(SPLIT_RSS_COUNTING)
  1331   struct task_rss_stat  rss_stat;
  1332 #endif
  1333 /* task state */
  1334   int exit_state;
  1335   int exit_code, exit_signal;
  1336   int pdeath_signal;  /*  The signal sent when the parent dies  */
  1337   unsigned int jobctl;  /* JOBCTL_*, siglock protected */
  1338
  1339   /* Used for emulating ABI behavior of previous Linux versions */
  1340   unsigned int personality;
  1341
  1342   unsigned did_exec:1;
  1343   unsigned in_execve:1; /* Tell the LSMs that the process is doing an
  1344          * execve */
  1345   unsigned in_iowait:1;
  1346
  1347   /* task may not gain privileges */
  1348   unsigned no_new_privs:1;
  1349
  1350   /* Revert to default priority/policy when forking */
  1351   unsigned sched_reset_on_fork:1;
  1352   unsigned sched_contributes_to_load:1;
  1353
  1354   pid_t pid;
  1355   pid_t tgid;
  1356
  1357 #ifdef CONFIG_CC_STACKPROTECTOR
  1358   /* Canary value for the -fstack-protector gcc feature */
  1359   unsigned long stack_canary;
  1360 #endif
  1361   /*
  1362    * pointers to (original) parent process, youngest child, younger sibling,
  1363    * older sibling, respectively.  (p->father can be replaced with
  1364    * p->real_parent->pid)
  1365    */
  1366   struct task_struct __rcu *real_parent; /* real parent process */
  1367   struct task_struct __rcu *parent; /* recipient of SIGCHLD, wait4() reports */
  1368   /*
  1369    * children/sibling forms the list of my natural children
  1370    */
  1371   struct list_head children;  /* list of my children */
  1372   struct list_head sibling; /* linkage in my parent's children list */
  1373   struct task_struct *group_leader; /* threadgroup leader */
  1374
  1375   /*
  1376    * ptraced is the list of tasks this task is using ptrace on.
  1377    * This includes both natural children and PTRACE_ATTACH targets.
  1378    * p->ptrace_entry is p's link on the p->parent->ptraced list.
  1379    */
  1380   struct list_head ptraced;
  1381   struct list_head ptrace_entry;
  1382
  1383   /* PID/PID hash table linkage. */
  1384   struct pid_link pids[PIDTYPE_MAX];
  1385   struct list_head thread_group;
  1386   struct list_head thread_node;
  1387
  1388   struct completion *vfork_done;    /* for vfork() */
  1389   int __user *set_child_tid;    /* CLONE_CHILD_SETTID */
  1390   int __user *clear_child_tid;    /* CLONE_CHILD_CLEARTID */
  1391
  1392   cputime_t utime, stime, utimescaled, stimescaled;
  1393   cputime_t gtime;
  1394 #ifndef CONFIG_VIRT_CPU_ACCOUNTING_NATIVE
  1395   struct cputime prev_cputime;
  1396 #endif
  1397 #ifdef CONFIG_VIRT_CPU_ACCOUNTING_GEN
  1398   seqlock_t vtime_seqlock;
  1399   unsigned long long vtime_snap;
  1400   enum {
  1401     VTIME_SLEEPING = 0,
  1402     VTIME_USER,
  1403     VTIME_SYS,
  1404   } vtime_snap_whence;
  1405 #endif
  1406   unsigned long nvcsw, nivcsw; /* context switch counts */
  1407   struct timespec start_time;     /* monotonic time */
  1408   struct timespec real_start_time;  /* boot based time */
  1409 /* mm fault and swap info: this can arguably be seen as either mm-specific or thread-specific */
  1410   unsigned long min_flt, maj_flt;
  1411
  1412   struct task_cputime cputime_expires;
  1413   struct list_head cpu_timers[3];
  1414
  1415 /* process credentials */
  1416   const struct cred __rcu *real_cred; /* objective and real subjective task
  1417            * credentials (COW) */
  1418   const struct cred __rcu *cred;  /* effective (overridable) subjective task
  1419            * credentials (COW) */
  1420   char comm[TASK_COMM_LEN]; /* executable name excluding path
  1421              - access with [gs]et_task_comm (which lock
  1422                it with task_lock())
  1423              - initialized normally by setup_new_exec */
  1424 /* file system info */
  1425   int link_count, total_link_count;
  1426 #ifdef CONFIG_SYSVIPC
  1427 /* ipc stuff */
  1428   struct sysv_sem sysvsem;
  1429 #endif
  1430 /* CPU-specific state of this task */
  1431   struct thread_struct thread;
  1432 /* filesystem information */
  1433   struct fs_struct *fs;
  1434 /* open file information */
  1435   struct files_struct *files;
  1436 /* namespaces */
  1437   struct nsproxy *nsproxy;
  1438 /* signal handlers */
  1439   struct signal_struct *signal;
  1440   struct sighand_struct *sighand;
  1441
  1442   sigset_t blocked, real_blocked;
  1443   sigset_t saved_sigmask; /* restored if set_restore_sigmask() was used */
  1444   struct sigpending pending;
  1445
  1446   unsigned long sas_ss_sp;
  1447   size_t sas_ss_size;
  1448   int (*notifier)(void *priv);
  1449   void *notifier_data;
  1450   sigset_t *notifier_mask;
  1451   struct callback_head *task_works;
  1452
  1453   struct audit_context *audit_context;
  1454 #ifdef CONFIG_AUDITSYSCALL
  1455   kuid_t loginuid;
  1456   unsigned int sessionid;
  1457 #endif
  1458   struct seccomp seccomp;
  1459
  1460 /* Thread group tracking */
  1461     u32 parent_exec_id;
  1462     u32 self_exec_id;
  1463 /* Protection of (de-)allocation: mm, files, fs, tty, keyrings, mems_allowed,
  1464  * mempolicy */
  1465   spinlock_t alloc_lock;
  1466
  1467   /* Protection of the PI data structures: */
  1468   raw_spinlock_t pi_lock;
  1469
  1470 #ifdef CONFIG_RT_MUTEXES
  1471   /* PI waiters blocked on a rt_mutex held by this task */
  1472 #ifndef __GENKSYMS__
  1473   struct rb_root pi_waiters;
  1474   struct rb_node *pi_waiters_leftmost;
  1475 #else
  1476   struct plist_head pi_waiters;
  1477 #endif
  1478   /* Deadlock detection and priority inheritance handling */
  1479   struct rt_mutex_waiter *pi_blocked_on;
  1480 #endif
  1481
  1482 #ifdef CONFIG_DEBUG_MUTEXES
  1483   /* mutex deadlock detection */
1484   struct mutex_waiter *blocked_on;
  1485 #endif
  1486 #ifdef CONFIG_TRACE_IRQFLAGS
  1487   unsigned int irq_events;
  1488   unsigned long hardirq_enable_ip;
  1489   unsigned long hardirq_disable_ip;
  1490   unsigned int hardirq_enable_event;
  1491   unsigned int hardirq_disable_event;
  1492   int hardirqs_enabled;
  1493   int hardirq_context;
  1494   unsigned long softirq_disable_ip;
  1495   unsigned long softirq_enable_ip;
  1496   unsigned int softirq_disable_event;
  1497   unsigned int softirq_enable_event;
  1498   int softirqs_enabled;
  1499   int softirq_context;
  1500 #endif
  1501 #ifdef CONFIG_LOCKDEP
  1502 # define MAX_LOCK_DEPTH 48UL
  1503   u64 curr_chain_key;
  1504   int lockdep_depth;
1505   unsigned int lockdep_recursion;
  1506   struct held_lock held_locks[MAX_LOCK_DEPTH];
  1507   gfp_t lockdep_reclaim_gfp;
  1508 #endif
  1509
  1510 /* journalling filesystem info */
  1511   void *journal_info;
  1512
  1513 /* stacked block device info */
  1514   struct bio_list *bio_list;
  1515
  1516 #ifdef CONFIG_BLOCK
  1517 /* stack plugging */
  1518   struct blk_plug *plug;
  1519 #endif
  1520
  1521 /* VM state */
  1522   struct reclaim_state *reclaim_state;
  1523
  1524   struct backing_dev_info *backing_dev_info;
  1525
1526   struct io_context *io_context;
  1527
  1528   unsigned long ptrace_message;
  1529   siginfo_t *last_siginfo; /* For ptrace use.  */
  1530   struct task_io_accounting ioac;
  1531 #if defined(CONFIG_TASK_XACCT)
  1532   u64 acct_rss_mem1;  /* accumulated rss usage */
  1533   u64 acct_vm_mem1; /* accumulated virtual memory usage */
  1534   cputime_t acct_timexpd; /* stime + utime since last update */
  1535 #endif
  1536 #ifdef CONFIG_CPUSETS
  1537   nodemask_t mems_allowed;  /* Protected by alloc_lock */
  1538   seqcount_t mems_allowed_seq;  /* Seqence no to catch updates */
  1539   int cpuset_mem_spread_rotor;
  1540   int cpuset_slab_spread_rotor;
  1541 #endif
  1542 #ifdef CONFIG_CGROUPS
  1543   /* Control Group info protected by css_set_lock */
  1544   struct css_set __rcu *cgroups;
  1545   /* cg_list protected by css_set_lock and tsk->alloc_lock */
  1546   struct list_head cg_list;
1547 #endif
  1548 #ifdef CONFIG_FUTEX
  1549   struct robust_list_head __user *robust_list;
  1550 #ifdef CONFIG_COMPAT
  1551   struct compat_robust_list_head __user *compat_robust_list;
  1552 #endif
  1553   struct list_head pi_state_list;
  1554   struct futex_pi_state *pi_state_cache;
  1555 #endif
  1556 #ifdef CONFIG_PERF_EVENTS
  1557   struct perf_event_context *perf_event_ctxp[perf_nr_task_contexts];
  1558   struct mutex perf_event_mutex;
  1559   struct list_head perf_event_list;
  1560 #endif
  1561 #ifdef CONFIG_NUMA
  1562   struct mempolicy *mempolicy;  /* Protected by alloc_lock */
  1563   short il_next;
  1564   short pref_node_fork;
  1565 #endif
  1566 #ifdef CONFIG_NUMA_BALANCING
  1567   int numa_scan_seq;
1568   unsigned int numa_scan_period;
  1569   unsigned int numa_scan_period_max;
  1570   int numa_preferred_nid;
  1571   unsigned long numa_migrate_retry;
  1572   u64 node_stamp;     /* migration stamp  */
  1573   u64 last_task_numa_placement;
  1574   u64 last_sum_exec_runtime;
  1575   struct callback_head numa_work;
  1576
  1577   struct list_head numa_entry;
  1578   struct numa_group *numa_group;
  1579
  1580   /*
  1581    * Exponential decaying average of faults on a per-node basis.
  1582    * Scheduling placement decisions are made based on the these counts.
  1583    * The values remain static for the duration of a PTE scan
  1584    */
  1585   unsigned long *numa_faults_memory;
  1586   unsigned long total_numa_faults;
  1587
  1588   /*
  1589    * numa_faults_buffer records faults per node during the current
  1590    * scan window. When the scan completes, the counts in
  1591    * numa_faults_memory decay and these values are copied.
  1592    */
  1593   unsigned long *numa_faults_buffer_memory;
  1594
  1595   /*
  1596    * Track the nodes the process was running on when a NUMA hinting
  1597    * fault was incurred.
  1598    */
  1599   unsigned long *numa_faults_cpu;
  1600   unsigned long *numa_faults_buffer_cpu;
  1601
  1602   /*
  1603    * numa_faults_locality tracks if faults recorded during the last
  1604    * scan window were remote/local. The task scan period is adapted
  1605    * based on the locality of the faults with different weights
  1606    * depending on whether they were shared or private faults
  1607    */
  1608   unsigned long numa_faults_locality[2];
  1609
1610   unsigned long numa_pages_migrated;
  1611 #endif /* CONFIG_NUMA_BALANCING */
  1612
  1613   struct rcu_head rcu;
  1614
  1615   /*
  1616    * cache last used pipe for splice
  1617    */
  1618   struct pipe_inode_info *splice_pipe;
  1619
  1620   struct page_frag task_frag;
  1621
  1622 #ifdef  CONFIG_TASK_DELAY_ACCT
  1623   struct task_delay_info *delays;
  1624 #endif
  1625 #ifdef CONFIG_FAULT_INJECTION
  1626   int make_it_fail;
  1627 #endif
  1628   /*
  1629    * when (nr_dirtied >= nr_dirtied_pause), it's time to call
  1630    * balance_dirty_pages() for some dirty throttling pause
1631    */
  1632   int nr_dirtied;
  1633   int nr_dirtied_pause;
  1634   unsigned long dirty_paused_when; /* start of a write-and-pause period */
  1635
  1636 #ifdef CONFIG_LATENCYTOP
  1637   int latency_record_count;
  1638   struct latency_record latency_record[LT_SAVECOUNT];
  1639 #endif
  1640   /*
  1641    * time slack values; these are used to round up poll() and
  1642    * select() etc timeout values. These are in nanoseconds.
  1643    */
  1644   unsigned long timer_slack_ns;
  1645   unsigned long default_timer_slack_ns;
  1646
  1647 #if defined(CONFIG_FUNCTION_GRAPH_TRACER) && !defined(CONFIG_S390)
  1648   /* Index of current stored address in ret_stack */
  1649   int curr_ret_stack;
  1650   /* Stack of return addresses for return function tracing */
  1651   struct ftrace_ret_stack *ret_stack;
1652   /* time stamp for last schedule */
  1653   unsigned long long ftrace_timestamp;
  1654   /*
  1655    * Number of functions that haven't been traced
  1656    * because of depth overrun.
  1657    */
  1658   atomic_t trace_overrun;
  1659   /* Pause for the tracing */
  1660   atomic_t tracing_graph_pause;
  1661 #endif
  1662 #ifdef CONFIG_TRACING
  1663   /* state flags for use by tracers */
  1664   unsigned long trace;
  1665   /* bitmask and counter of trace recursion */
  1666   unsigned long trace_recursion;
  1667 #endif /* CONFIG_TRACING */
  1668 #ifdef CONFIG_MEMCG /* memcg uses this to do batch job */
  1669   struct memcg_batch_info {
  1670     int do_batch; /* incremented when batch uncharge started */
  1671     struct mem_cgroup *memcg; /* target memcg of uncharge */
  1672     unsigned long nr_pages; /* uncharged usage */
1673     unsigned long memsw_nr_pages; /* uncharged mem+swap usage */
  1674   } memcg_batch;
  1675   unsigned int memcg_kmem_skip_account;
  1676 #endif
  1677 #ifdef CONFIG_HAVE_HW_BREAKPOINT
  1678   atomic_t ptrace_bp_refcnt;
  1679 #endif
  1680 #if !defined(CONFIG_S390) && defined(CONFIG_UPROBES)
  1681   struct uprobe_task *utask;
  1682 #endif
  1683 #if defined(CONFIG_BCACHE) || defined(CONFIG_BCACHE_MODULE)
  1684   unsigned int  sequential_io;
  1685   unsigned int  sequential_io_avg;
  1686 #endif
  1687
  1688   /* reserved for Red Hat */
  1689 #ifdef CONFIG_DETECT_HUNG_TASK
  1690   RH_KABI_USE(1, unsigned long last_switch_count)
  1691 #else
  1692   RH_KABI_RESERVE(1)
  1693 #endif
  1694   RH_KABI_USE(2, unsigned long atomic_flags)
  1695 #if defined(CONFIG_S390) && defined(CONFIG_UPROBES)
  1696   RH_KABI_USE(3, struct uprobe_task *utask)
  1697 #else
  1698   RH_KABI_RESERVE(3)
  1699 #endif
  1700   /* This would be in rss_stat[MM_SHMEMPAGES] if not for kABI */
  1701   RH_KABI_USE(4, int mm_shmempages)
  1702   RH_KABI_RESERVE(5)
  1703   RH_KABI_RESERVE(6)
  1704   RH_KABI_RESERVE(7)
  1705   RH_KABI_RESERVE(8)
  1706 #ifndef __GENKSYMS__
  1707 #ifdef CONFIG_MEMCG
  1708   struct memcg_oom_info {
  1709     struct mem_cgroup *memcg;
  1710     gfp_t gfp_mask;
  1711     int order;
  1712     unsigned int may_oom:1;
  1713   } memcg_oom;
  1714 #endif
  1715 #ifdef CONFIG_ARCH_WANT_BATCHED_UNMAP_TLB_FLUSH
  1716   struct tlbflush_unmap_batch tlb_ubc;
  1717 #endif
  1718 #if defined(CONFIG_FUNCTION_GRAPH_TRACER) && defined(CONFIG_S390)
  1719   /* Index of current stored address in ret_stack */
  1720   int curr_ret_stack;
  1721   /* Stack of return addresses for return function tracing */
  1722   struct ftrace_ret_stack *ret_stack;
  1723   /* time stamp for last schedule */
  1724   unsigned long long ftrace_timestamp;
  1725   /*
  1726    * Number of functions that haven't been traced
  1727    * because of depth overrun.
  1728    */
  1729   atomic_t trace_overrun;
  1730   /* Pause for the tracing */
  1731   atomic_t tracing_graph_pause;
  1732 #endif
  1733   struct sched_dl_entity dl;
  1734   #ifdef CONFIG_SMP
  1735     struct rb_node pushable_dl_tasks;
  1736   #endif
  1737   struct sched_statistics statistics;
  1738 #endif /* __GENKSYMS__ */
  1739 };
