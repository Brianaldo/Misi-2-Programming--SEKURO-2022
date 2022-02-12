# Penjelasan algoritma yang dipakai

Jika suatu fungsi f(x) di-integralkan dengan batas bawah a dan batas bawah b, maka

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20%5Cint_%7Ba%7D%5E%7Bb%7D%20f%28x%29%20%5C%2Cdx">

Untuk mengubah sebuah integral definit menjadi sebuah penjumlahan Riemann,

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20%5CDelta%20x%20%3D%20%5Cfrac%7Bb-a%7D%7Bn%7D">

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20x_i%20%3D%20a%20&plus;%20i%5CDelta%20x">

Untuk mempermudah perhitungan, kita akan membuat f(x) sebagai fungsi derajat 3, yaitu

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20f%28x%29%20%3D%20px%5E3&plus;qx%5E2&plus;rx&plus;s">

Kemudian kita akan mengganti x,

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20%5Cint_%7Ba%7D%5E%7Bb%7D%20f%28x%29%20%5C%2Cdx%20%3D%20%5Clim_%7Bn%5Cto%5Cinfty%7D%20%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%20f%28x%29%20%5CDelta%20x">

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20%5Cint_%7Ba%7D%5E%7Bb%7D%20px%5E3&plus;qx%5E2&plus;rx&plus;s%20%5C%2Cdx%20%3D%20%5Clim_%7Bn%5Cto%5Cinfty%7D%20%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%20%28%29p%28a&plus;%5Cfrac%7Bi%5CDelta%20x%7D%7Bn%7D%29%5E3%20&plus;%20q%28a&plus;%5Cfrac%7Bi%5CDelta%20x%7D%7Bn%7D%29%5E2%20&plus;%20r%28a&plus;%5Cfrac%7Bi%5CDelta%20x%7D%7Bn%7D%29%20&plus;%20s%29%20%28%5Cfrac%7Bb-a%7D%7Bn%7D%29">

Lalu, kita akan memasukkan nilai Δx dan membuka eksponen

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B150%7D%20%5Cbg_black%20%5Csmall%20%5Clim_%7Bn%5Cto%5Cinfty%7D%20%5Csum%5E%7Bn%7D_%7Bi%3D1%7D%20%28p%28%5Cfrac%7B%28b-a%29i%7D%7Bn%7D%29%5E3%20&plus;%203a%28%5Cfrac%7B%28b-a%29i%7D%7Bn%7D%29%5E2&plus;3a%5E2%28%5Cfrac%7B%28b-a%29i%7D%7Bn%7D%29&plus;a%5E3%29&plus;q%28%28%5Cfrac%7B%28b-a%29i%7D%7Bn%7D%29%5E2%20&plus;%202a%5Cfrac%7B%28b-a%29i%7D%7Bn%7D%29&plus;a%5E2%29&plus;r%28a&plus;%28%5Cfrac%7B%28b-a%29i%7D%7Bn%7D%29%29&plus;s%29%28%5Cfrac%7Bb-a%7D%7Bn%7D%29">

Kemudian, kita akan mengali fungsi tersebut dengan Δx disebelah kanan

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B150%7D%20%5Cbg_black%20%5Csmall%20%5Clim_%7Bn%5Cto%5Cinfty%7D%20%5Csum_%7Bi%3D1%7D%5E%7B%5Cinfty%7D%20p%28%28b-a%29%5E4%5Cfrac%7Bi%5E3%7D%7Bn%5E4%7D%20&plus;%203a%28b-a%29%5E3%5Cfrac%7Bi%5E2%7D%7Bn%5E3%7D%20&plus;%203a%5E2%28b-a%29%5E2%5Cfrac%7Bi%7D%7Bn%5E2%7D%20&plus;%20a%5E3%28b-a%29%5Cfrac%7B1%7D%7Bn%7D%29&plus;%20q%28%28b-a%29%5E3%5Cfrac%7Bi%5E2%7D%7Bn%5E3%7D%20&plus;%202a%28b-a%29%5E2%5Cfrac%7Bi%7D%7Bn%5E2%7D%20&plus;%20a%5E2%28b-a%29%5Cfrac%7B1%7D%7Bn%7D%29&plus;%20r%28%28b-a%29%5E2%5Cfrac%7Bi%7D%7Bn%5E2%7D%20&plus;%20a%28b-a%29%5Cfrac%7B1%7D%7Bn%7D%29&plus;%20s%28b-a%29%5Cfrac%7B1%7D%7Bn%7D%29">

Untuk menghilangkan i, kita dapat melimitkan i dan n dengan rumus

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20%5Clim_%7Bn%5Cto%5Cinfty%7D%20%5Csum_%7Bi%3D1%7D%5E%7B%5Cinfty%7D%20%5Cfrac%7Bi%5Ej%7D%7Bn%5E%7B%28j&plus;1%29%7D%7D%20%3D%20%5Cfrac%7B1%7D%7Bj&plus;1%7D">

Sehingga

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B150%7D%20%5Cbg_black%20%5Csmall%20%5Cint_%7Ba%7D%5E%7Bb%7Df%28x%29%20%3D%20p%28%5Cfrac%7B1%7D%7B4%7D%28b-a%29%5E4%20&plus;%20%5Cfrac%7B3a%7D%7B3%7D%28b-a%29%5E3%20&plus;%20%5Cfrac%7B3a%5E2%7D%7B2%7D%28b-a%29%5E2%20&plus;%20a%5E3%28b-a%29%29&plus;%20q%28%5Cfrac%7B1%7D%7B3%7D%28b-a%29%5E3%20&plus;%20%5Cfrac%7B2a%7D%7B2%7D%28b-a%29%5E2%20&plus;%20a%5E2%28b-a%29%29&plus;%20r%28%5Cfrac%7B1%7D%7B2%7D%28b-a%29%5E2%20&plus;%20a%28b-a%29%29&plus;%20s%28b-a%29%29">

Perhatikan pada tiap persamaan polinomial yang dikali oleh masing-masing p, q, r, dan s

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20p%28%5Cfrac%7B1%7D%7B4%7D%28b-a%29%5E4%20&plus;%20%5Cfrac%7B3a%7D%7B3%7D%28b-a%29%5E3%20&plus;%20%5Cfrac%7B3a%5E2%7D%7B2%7D%28b-a%29%5E2%20&plus;%20a%5E3%28b-a%29%29">
<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20q%28%5Cfrac%7B1%7D%7B3%7D%28b-a%29%5E3%20&plus;%20%5Cfrac%7B2a%7D%7B2%7D%28b-a%29%5E2%20&plus;%20a%5E2%28b-a%29%29">
<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20r%28%5Cfrac%7B1%7D%7B2%7D%28b-a%29%5E2%20&plus;%20a%28b-a%29%29">
<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20s%28%28b-a%29%29">

Dapat dilihat bahwa tiap koefisien yang akan mengali (b-a) memiliki koefisien mirip dengan segitiga pascal urutan ke-(n+1), dengan n adalah pangkat (b-a) tertinggi pada persamaan polinom tersebut. Sehingga, kita dapat menyederhanakan rumus tersebut menjadi

<img src = "https://latex.codecogs.com/png.latex?%5Cdpi%7B200%7D%20%5Cbg_black%20%5Cfrac%7Ba%5E%7B%28n-1%29%7D%20%5Ccdot%20p%5Bn%5D%5Bi%5D%20%5Ccdot%20C%20%5Ccdot%20%28b-a%29%5E%7B%28i&plus;1%29%7D%7D%7Bi&plus;1%7D">

Dengan:
1. a = batas bawah
2. b = batas atas
3. n = pangkat tertinggi polinom x = (b-a)
4. i = pangkat yang sedang dicari nilainya
5. p[x][y] = segitiga pascal pada baris x urutan ke y
6. C = koefisien polinom x = (b-a)
