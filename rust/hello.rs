fn foo<'a , 'b>(s1:&'a,s2:'b)->&'a str
where 'b :'a{
	s2
}

