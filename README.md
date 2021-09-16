# FDF
For FDF, we will receive a given number of points to draw our wireframe from, but we will eventually need to draw lines between these points. For that we can use or [Wu's](https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm) or [Bresenham's](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) line algorithm, knowing that while the first makes lines in the prettiest way, the second makes it faster.

## Functions workflow:
### Alocate: 
![alt text](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/853d5a33-5884-4c0f-a1e7-1f8d4efac611/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210916%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210916T134820Z&X-Amz-Expires=86400&X-Amz-Signature=e6ea5c4e04da178a6a0791a9c97531dc25932bb3e5212d0a2dc67105eb5496fb&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

### Fill matrix: 
![alt text](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/eb16667c-5beb-4523-b502-0317f96e25a0/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210916%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210916T134923Z&X-Amz-Expires=86400&X-Amz-Signature=85dd0a59aaa18397d48061b6b08d7b4b5c69326e30d12aeaa4a853d3631bddfa&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)
![alt text](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/7dd19167-e051-496c-b2c1-9769c1175407/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210916%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210916T135055Z&X-Amz-Expires=86400&X-Amz-Signature=1e09aab7be28c7fd1a716770ceacb140f25e9862d45c21811b7e4576f8123080&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

## Maps:
###   42.fdf:
![alt text](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/43a80f36-c49d-48eb-ac84-0771ceb1496f/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210915%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210915T222535Z&X-Amz-Expires=86400&X-Amz-Signature=6a8b22f288961ca96c6bcbc4f449e01567866e903f693e2811823aca779a3119&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)
###   t1.fdf:
![alt text](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/2f14fc8b-65d4-45b1-98ca-12cc27c2ac46/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210915%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210915T222601Z&X-Amz-Expires=86400&X-Amz-Signature=27ae78365c32fd766fe2649378781555515bfb367e25dd7f56962a859ada240e&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)
###   t2.fdf:
![alt text](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/7729aadb-31d5-4b5b-a775-11ad30171326/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210913%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210913T163708Z&X-Amz-Expires=86400&X-Amz-Signature=1753f3768f4db53768ebea0281ba869c2f7dd869da1646d3f32197e398178c9b&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)
###   elem-fract.fdf:
![alt text](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/eb0f0fff-b5dc-4118-8a11-312404374c72/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210916%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210916T001314Z&X-Amz-Expires=86400&X-Amz-Signature=48371bebe3a0edee24a9dca6fb2b4e1b910962fc02a1e9cb55235d677264dd8a&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)
