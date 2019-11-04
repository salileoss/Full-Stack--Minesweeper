FROM mike314/boost_cpp:0.1.0

WORKDIR /opt/crowapp

COPY . .

RUN make

EXPOSE 18080

CMD [ "bin/server", "-t", "templates", "-s", "static" ]
