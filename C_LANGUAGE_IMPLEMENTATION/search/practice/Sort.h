for (int i1 = 0; i1 < UNITNUM; i1++)
{
	for (int i = 0; i < UNITNUM; i++)
	{
		if (array[i] > array[i + 1])
		{
			array[i] = array[i] + array[i + 1];
			array[i + 1] = array[i] - array[i + 1];
			array[i] = array[i] - array[i + 1];
		}
	}
}