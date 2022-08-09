EXECUTABLE= Actors_centrality_analyzer
DEBUG_EXT=	.debug

IMDB_EXT= .tsv
IMDB_COMPRESSED_EXT= .gz
IMDB_FILES_SHORT= name.basics title.basics title.principals
IMDB_FILES= ${IMDB_FILES_SHORT:=${IMDB_EXT}}
IMDB_FILES_COMPRESSED= ${IMDB_FILES:=${IMDB_COMPRESSED_EXT}}
IMDB_URL_DOWNLOAD= https://datasets.imdbws.com

CMD_DOWNLOAD=	wget -O
CMD_ECHO= echo
CMD_EXTRACT= gunzip
CMD_MAKE= make
CMD_SED= sed

all: ${IMDB_FILES} ${EXECUTABLE}

debug: ${IMDB_FILES} ${EXECUTABLE}${DEBUG_EXT}

${EXECUTABLE}: *.cpp *.h
	${CXX} ${CXXFLAGS} -O3 `${CMD_ECHO} $^ | ${CMD_SED} "s/[^ ]*\.h//g"`  -o $@

${EXECUTABLE}${DEBUG_EXT}: *.cpp *.h
	${CXX} ${CXXFLAGS} -g -O1 `${CMD_ECHO} $^ | ${CMD_SED} "s/[^ ]*\.h//g"`  -o $@

test:
	cd tests && ${MAKE}

clean:
	rm -f ${IMDB_FILES} \
				${IMDB_FILES_COMPRESSED} \
				${EXECUTABLE} \
				${EXECUTABLE}${DEBUG_EXT}
	cd tests && ${MAKE} clean

compress: clean
	rm -f ~/${EXECUTABLE}.tar.gz && \
	cd ~ && \
	tar -cvf ${EXECUTABLE}.tar ${EXECUTABLE} && \
	gzip ${EXECUTABLE}.tar

save: compress all

${IMDB_FILES}:
	${CMD_DOWNLOAD} \
	$@${IMDB_COMPRESSED_EXT} \
	${IMDB_URL_DOWNLOAD}/$@${IMDB_COMPRESSED_EXT} && \
	${CMD_EXTRACT} $@${IMDB_COMPRESSED_EXT}

.SUFFIXES: ${IMDB_EXT} ${IMDB_COMPRESSED_EXT}

${IMDB_EXT}${IMDB_COMPRESSED_EXT}:
	${CMD_EXTRACT} $^
