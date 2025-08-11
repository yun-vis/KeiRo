# KeiRo

`KeiRo` is a package for generating biological pathway diagrams, which contain the following features:

- `Harmony` is a harmonized layout algorithm for biological pathways.
- `Lens` is a lens technique for exploring diagrams semantically.
- `Metabopolis` is a new layout algorithm for biological pathways, which has been
developed by [Hsiang-Yun Wu][yw], [Martin Nöllenburg][mn], and [Ivan Viola][iv],
in the group [Research Unit of Computer Graphics][rucg] at [TU Wien][tuwien] in
Vienna, Austria. The c++ library was developed by [Hsiang-Yun Wu][yw].

## How to cite?

- Hsiang-Yun Wu, Martin Nöllenburg, Filipa L. Sousa, and Ivan Viola, Metabopolis:
  Scalable Network Layout for Biological Pathway Diagrams in Urban Map Style, BMC
  Bioinformatics, Vol. 20, No. 1, p. 187, 2019.
  [[Paper][bmc-paper]] [[Video][bmc-video]]

## Installing

### Prerequisites

- [cmake 3.10+][cmake]
- [qt 5.13][qt5]
- [Boost Graph Library 1.71][boost]
- [libsbml 5.17][sbml]
- [libSBGN 2.0][sbgn]
- [Eigen3 3.3][eigen]
- [CGAL 4 4.14.3][cgal]

### Build

Clone the KeiRo repository into a directory `KeiRo`.

```
$ git clone KeiRo
$ cd KeiRo
$ mkdir build
$ cd build
$ cmake ../
$ make
```

## Using KeiRo

```
$ ./KeiRo
```

### Tested environment

- Ubuntu 20.04LTS, 22.04 LTS
- Mac OS 10.12


## Acknowledgement

The project leading to this submission has received funding from the European Union
Horizon 2020 research and innovation programme under the Marie Sklodowska-Curie
grant agreement [No. 747985][msca] and from the Vienna Science and Technology Fund (WWTF)
through project [VRG11-010][vrg11].

[cmake]: https://cmake.org/
[qt5]: https://www.qt.io/
[boost]: https://www.boost.org/
[sbml]: https://sbml.org/
[sbgn]: https://github.com/fbergmann/libSBGN2/
[eigen]: http://eigen.tuxfamily.org/
[cgal]: https://www.cgal.org/

[rucg]: https://www.cg.tuwien.ac.at/
[tuwien]: https://www.tuwien.ac.at/
[yw]: https://www.cg.tuwien.ac.at/staff/HsiangYunWu.html
[mn]: https://www.ac.tuwien.ac.at/people/noellenburg/
[iv]: https://www.cg.tuwien.ac.at/staff/IvanViola.html
[msca]: https://www.cg.tuwien.ac.at/research/projects/BioNetIllustration/
[vrg11]: https://www.cg.tuwien.ac.at/research/projects/illvisation/

<!-- Metabopolis -->
[bmc-paper]: https://doi.org/10.1016/j.visinf.2018.12.006
[bmc-video]: https://www.youtube.com/watch?v=AhWCIGTxqAg
