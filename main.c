int main(int argc, char **argv)
{
	if (argc < 2)
		ft_printf("%s", ERROR_1);
	check_args(argc, argv);
	return (0);
}