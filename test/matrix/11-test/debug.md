
(gdb) p a
$42 = (Array) 0x607010
(gdb) p *a
$43 = {size = 4, data = 0x607030}
(gdb) p *a->data
$44 = 56
(gdb) p *a->data@4
$45 = {56, 40, 97, 78}
(gdb) p *a->data[0]
Attempt to take contents of a non-pointer value.
(gdb) p a->data[0]
$46 = 56
(gdb) p a->data[1]
$47 = 40
(gdb) p a->data[2]
$48 = 97
(gdb) p a->data[3]
$49 = 78
(gdb) p &(a->data[0])
$50 = (Scalar *) 0x607030
(gdb) p &(a->data[1])
$51 = (Scalar *) 0x607034
(gdb) p &(a->data[2])
$52 = (Scalar *) 0x607038
(gdb) p &(a->data[3])
$53 = (Scalar *) 0x60703c
(gdb) p *((Scalar *) 0x607030)
$54 = 56
(gdb) p *((Scalar *) 0x607034)
$55 = 40
(gdb)
