# Actors centrality analyzer

**Actors centrality analyzer** is a software that I have written for a univesity exam in 2021. It creates a graph where
- each node corresponds to an actor;
- two actors are linked if and only if they have worked together in some movie.

The software then computes actors importance according to different mathematical concepts of centrality.

## Data source

Data for the software is taken from [IMDb](https://www.imdb.com/). The data itself is not included in the source code: a Makefile is provided to download it instead. A few data has however been used in the tests directory.

**Information courtesy of \
IMDb \
(https://www.imdb.com). \
Used with permission.**
