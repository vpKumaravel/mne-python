.. _changes_1_1_0:

Version 1.1.0 (2022-08-03)
--------------------------

Enhancements
~~~~~~~~~~~~
- Added new built-in montage R-Net 128 Ch (Brain Products) (:gh:`10974` by :newcontrib:`Ilias Machairas`)

- :class:`~mne.channels.DigMontage` objects can now be checked for equality via ``==`` (:gh:`10942` by :newcontrib:`Tziona NessAiver`)

- Add a note to clarify the inclusion of average referencing gain matrix during whitening (:gh:`10922` by :newcontrib:`Mingjian He`)

- Add time axis scale bar for :meth:`mne.Epochs.plot` using matplotlib backend (:gh:`10736` by :newcontrib:`Jordan Drew`)

- Add :func:`mne.bem.distance_to_bem` to find depth of source positions (:gh:`10632` by :newcontrib:`Matt Courtemanche`)

- Add support for ahdr files in :func:`mne.io.read_raw_brainvision` (:gh:`10515` by :newcontrib:`Alessandro Tonin`)

- Add support for reading data from Gowerlabs devices to :func:`mne.io.read_raw_snirf` (:gh:`10555` by :newcontrib:`Samuel Powell` and `Robert Luke`_)

- Add built-in sensor layout files for Geodesic Head Web 130 and 280 devices (:gh:`10627` by `Evan Hathaway`_)

- Add ``mne-icalabel`` to :func:`mne.sys_info` (:gh:`10615` by `Adam Li`_)

- Add support for ``overview_mode`` in :meth:`raw.plot() <mne.io.Raw.plot>` and related functions/methods (:gh:`10501` by `Eric Larson`_)

- Add :meth:`mne.io.Raw.crop_by_annotations` method to get chunks of Raw data based on :class:`mne.Annotations`. (:gh:`10460` by `Alex Gramfort`_)

- The ``pick_channels`` method gained a ``verbose`` parameter, allowing e.g. to suppress messages about removed projectors (:gh:`10544` by `Richard Höchenberger`_)

- Add :func:`mne.viz.plot_projs_joint` for joint plotting of projectors and Evoked (:gh:`10720` by `Eric Larson`_)

- The :func:`mne.make_forward_dipole` function can now take a list of dipoles to make a multi-dipole forward models (:gh:`10464` by `Marijn van Vliet`_)

- Add ``mode='outlines'`` support to :meth:`mne.Dipole.plot_locations` and :func:`mne.viz.plot_dipole_locations` (:gh:`10699` by `Eric Larson`_)

- Add :meth:`mne.preprocessing.ICA.find_bads_muscle` to find muscle-related ICA components with an example, :ref:`ex-muscle-ica` (:gh:`10534` by `Alex Rockhill`_)

- Add example of Xfit-style ECD modeling using multiple dipoles (:gh:`10464` by `Marijn van Vliet`_)

- Add ``head_source`` argument to :func:`mne.make_field_map` to allow selecting which head source to use (:gh:`10568` by `Eric Larson`_)

- Add support for ``n_jobs=None`` to support :func:`joblib:joblib.parallel_backend` for more precise control over parallelization (:gh:`10567` by `Eric Larson`_)

- It is now possible to compute inverse solutions with restricted source orientations using discrete forward models (:gh:`10464` by `Marijn van Vliet`_)

- The new function :func:`mne.preprocessing.maxwell_filter_prepare_emptyroom` simplifies the preconditioning of an empty-room recording for our Maxwell filtering operations (:gh:`10533` by `Richard Höchenberger`_ and `Eric Larson`_)

- Add keyboard shortcuts to toggle :meth:`mne.preprocessing.ICA.plot_properties` topomap channel types ('t') and power spectral density log-scale ('l') (:gh:`10557` by `Alex Rockhill`_)

- Add ``--mri``, and ``--threshold`` options to :ref:`mne make_scalp_surfaces` to improve head surface mesh extraction (:gh:`10591` by `Eric Larson`_)

- Add :func:`mne.preprocessing.compute_bridged_electrodes` to detect EEG electrodes with shared spatial sources due to a conductive medium connecting two or more electrodes, add :ref:`ex-eeg-bridging` for an example and :func:`mne.viz.plot_bridged_electrodes` to help visualize (:gh:`10571` by `Alex Rockhill`_)

- Add ``'nearest'`` as an option for the ``image_interp`` argument in :func:`mne.viz.plot_topomap` to plot a topomap without interpolation using a Voronoi parcelation (:gh:`10571` by `Alex Rockhill`_)

- Add :func:`mne.preprocessing.interpolate_bridged_electrodes` to use the spatially smeared signal to get a better interpolation rather than dropping those channels (:gh:`10587` by `Alex Rockhill`_)

- Add support for hemoglobin type fNIRS data to temporal derivative distribution repair (TDDR) :func:`mne.preprocessing.nirs.temporal_derivative_distribution_repair` (:gh:`10125` by `Johann Benerradi`_)

- :func:`mne.viz.plot_evoked_topomap` and :meth:`mne.Evoked.plot_topomap` now display the time range the map was averaged over if ``average`` was passed (:gh:`10606` by `Richard Höchenberger`_)

- :func:`mne.viz.plot_evoked_topomap` and :meth:`mne.Evoked.plot_topomap` can now average the topographic maps across different time periods for each time point. To do this, pass a list of periods via the ``average`` parameter (:gh:`10610` by `Richard Höchenberger`_)

- :func:`mne.viz.plot_evoked` and :meth:`mne.Evoked.plot` gained a new parameter, ``highlight``, to visually highlight time periods of interest (:gh:`10614` by `Richard Höchenberger`_)

- Added fNIRS support to :func:`mne.Info.get_montage` (:gh:`10611` by `Robert Luke`_)

- Add :func:`mne.viz.plot_ch_adjacency` to visualize and manually edit the channel adjacency matrix (:gh:`10633` by `Mikołaj Magnuski`_)

- Add :meth:`mne.viz.Brain.get_view` to get the current camera parameters such that they can be passed to :meth:`mne.viz.Brain.show_view` (:gh:`10661` by `Alex Rockhill`_)

- Added support for Aurora version 2021.9.0.6 to :func:`mne.io.read_raw_nirx` (:gh:`10668` by `Robert Luke`_)

- Added BrainVision format (``.vhdr``, ``.vmrk``, ``.eeg``) to :func:`mne.export.export_raw` (:gh:`10681` by `Stefan Appelhoff`_)

- Added ``export`` method to :class:`mne.Evoked` (:gh:`10681` by `Stefan Appelhoff`_)

- Add timeformat ``YYYY/MM/DD`` to ``mne.io.ctf.info._convert_time`` (:gh:`10674` by `Simon Kern`_)

- :meth:`mne.Report.add_figure` and :meth:`mne.Report.add_image` gained a new parameter, ``section``, allowing to put multiple figures or images into the same "content block". Previously, the only way to group figures and images was by means of a slider, which sometimes made content hard to discover. The slider remains available as an alternative (:gh:`10694` by `Richard Höchenberger`_)

- All functions and methods that plot topographic maps for EEG (2D projections of the EEG sensor locations) now accept the parameter value ``sphere='eeglab'`` to lay out the sensors with respect to the head circle in a similar way to how EEGLAB does, i.e., T7/T8 and Fpz/Oz are placed directly on the circle for template montages (:gh:`10572` by `Richard Höchenberger`_)

- :func:`mne.channels.get_builtin_montages` gained a new parameter, ``descriptions``, which allows to retrieve the descriptions of the montages in addition to their names (:gh:`10373` by `Richard Höchenberger`_)

- Add ``include`` option to :meth:`mne.io.read_raw_edf`, :meth:`mne.io.read_raw_bdf` and :meth:`mne.io.read_raw_gdf`. (:gh:`10734` by `Michiru Kaneda`_)

- :func:`mne.gui.coregistration` gained a new parameter, ``fullscreen``, to start the GUI in fullscreen mode (:gh:`10284` by `Richard Höchenberger`_)

- The built-in FieldTrip channel adjacency matrices, which can be read via :func:`~mne.channels.read_ch_adjacency`, have been synchronized with FieldTrip again. This means that numerous new adjacencies have been added, most notably those for standard 10-05 and 10-20 montages (:gh:`10749` by `Richard Höchenberger`_)

- :meth:`mne.Evoked.plot_field` gained a new parameter, ``interaction``, to control the rotation axes when interacting with the head (:gh:`10788` by `Richard Höchenberger`_)

- Add :func:`mne.read_evoked_besa` for reading evokeds from BESA ``.avr`` and ``.mul`` files. (:gh:`10892` by `Marijn van Vliet`_)

- Add :meth:`mne.time_frequency.EpochsTFR.decimate` to reduce size of time-frequency epochs objects (:gh:`10940` by `Alex Rockhill`_)

- Add an alias that maps EGI reference channel names (``VREF`` or ``Vertex Reference``) to the electrode name in the standard EGI montages (``Cz``). Now setting standard EGI montages with :meth:`~mne.io.Raw.set_montage` with ``match_alias=True`` will avoid raising an error (:gh:`10823` by `Scott Huberty`_)

- Add provenance in :func:`mne.time_frequency.EpochsTFR.apply_baseline` (:gh:`10979` by `Alex Rockhill`_)

Bugs
~~~~
- Fix bug in ``mne.surface._project_onto_surface`` for the condition ``method != 'accurate' and return_nn`` (:gh:`10930` by `Christian O'Reilly`_)

- Fix bug in :func:`mne.export.export_raw` to ignore None value in filenames attribute of :class:`mne.io.RawArray` (:gh:`10927` by :newcontrib:`Reza Nasri`)

- Fix bug in :func:`mne.io.read_raw_edf` to allow reading in all Hypnodyne ZMax EDFs to be read in without issues (:gh:`10754` by :newcontrib:`Frederik Weber`)

- Fix bug in :func:`mne.Epochs.drop_bad` where data was loaded although no rejection had to be performed (:gh:`10718` by :newcontrib:`Lukas Gemein`)

- Pick also bad channels when selecting T1T2 magnetometers in :func:`mne.preprocessing.maxwell_filter` (:gh:`10639` by :newcontrib:`Matti Toivonen`)

- Make ``color`` parameter check in in :func:`mne.viz.plot_evoked_topo` consistent (:gh:`10217` by :newcontrib:`T. Wang` and `Stefan Appelhoff`_)

- Fix bug in :func:`mne.io.read_raw_brainvision` when BrainVision data are acquired with the Brain Products "V-Amp" amplifier and disabled lowpass filter is marked with value ``0`` (:gh:`10517` by :newcontrib:`Alessandro Tonin`)

- Fix bug in :func:`mne.pick_types` and related methods where ``csd=True`` was not passed handled properly (:gh:`10470` by :newcontrib:`Matthias Dold`)

- Fix bug where plots produced using the ``'qt'`` / ``mne_qt_browser`` backend could not be added using :meth:`mne.Report.add_figure` (:gh:`10485` by `Eric Larson`_)

- Fix bug where ``theme`` was not handled properly in :meth:`mne.io.Raw.plot` (:gh:`10487`, :gh:`10500` by `Mathieu Scheltienne`_ and `Eric Larson`_)

- Fix bug in :meth:`raw.crop(start, stop) <mne.io.Raw.crop>` that would cause annotations to be erroneously shifted when ``start != 0`` and no measurement date was set. (:gh:`10491` by `Eric Larson`_)

- Fix bug in :func:`mne.io.read_raw_bti` where unknown electrode locations were not handled properly (:gh:`10662` by `Eric Larson`_)

- Fix bug in :func:`mne.io.read_raw_ctf` on Windows where large files could not be read (:gh:`10866` by `Eric Larson`_)

- Fix bug in :func:`mne.io.read_raw_ctf` where invalid measurement dates were not handled properly (:gh:`10957` by `Jean-Remi King`_ and `Eric Larson`_)

- Rendering issues with recent MESA releases can be avoided by setting the new environment variable``MNE_3D_OPTION_MULTI_SAMPLES=1`` or using :func:`mne.viz.set_3d_options` (:gh:`10513` by `Eric Larson`_)

- Fix behavior for the ``pyvista`` 3D renderer's ``quiver3D`` function so that default arguments plot a glyph in ``arrow`` mode (:gh:`10493` by `Alex Rockhill`_)

- Retain epochs metadata when using :func:`mne.channels.combine_channels` (:gh:`10504` by `Clemens Brunner`_)

- Fix epochs indexing with metadata containing boolean type and missing values (:gh:`10705` by `Clemens Brunner`_ and `Alex Gramfort`_)

- Fix reading of fiducial locations in :func:`mne.io.read_raw_eeglab` (:gh:`10521` by `Alex Gramfort`_)

- Prevent creation of montage with invalid ``[x, y, z]`` coordinates with :func:`mne.channels.make_dig_montage` (:gh:`10547` by `Mathieu Scheltienne`_)

- Fix bug in coregistration GUI that prevented it from starting up if only a high-resolution head model was available (:gh:`10543` by `Richard Höchenberger`_)

- Fix bug with :class:`mne.Epochs.add_reference_channels` where attributes were not updated properly so subsequent `~mne.Epochs.pick_types` calls were broken (:gh:`10912` by `Eric Larson`_)
-
- Fix bug in the :class:`mne.viz.Brain` tool bar that prevented the buttons to call the corresponding feature (:gh:`10560` by `Guillaume Favelier`_)

- Fix issue with saving epochs once :func:`~mne.preprocessing.compute_current_source_density` has been used if a rejection threshold was used first (:gh:`10619` by `Alex Rockhill`_ and `Richard Höchenberger`_)

- Fix bug in :func:`mne.viz.plot_evoked_image` that would cause incorrect sub-titles when using ``group_by`` (:gh:`10618` by `Reza Shoorangiz`_)

- Reduce memory usage when loading an EDF file with ``preload=False`` (:gh:`10638` by `Clemens Brunner`_)

- Fix bug in :meth:`mne.io.Raw.get_channel_types` and related methods where ``unique=True`` would return a :class:`python:set` with arbitrary order rather than a :class:`python:list` that preserves the same order as ``inst.ch_names`` (:gh:`10720` by `Eric Larson`_)

- In :func:`mne.preprocessing.find_bad_channels_maxwell`, do not re-filter the data if a low-pass filter with the requested frequency has already been applied (:gh:`10664` by `Richard Höchenberger`_)

- Fix a problem in :meth:`mne.Evoked.get_peak`, where under certain circumstances the ``mode`` parameters ``'pos'`` and ``'neg'`` were not honored when ``tmin`` and/or ``tmax`` were passed as well (:gh:`10686` by `Richard Höchenberger`_)

- :func:`mne.read_evokeds`, :func:`mne.channels.read_custom_montage`, :func:`mne.channels.read_dig_hpts`, :func:`mne.channels.read_dig_polhemus_isotrak`, and :func:`mne.channels.read_polhemus_fastscan` now correctly expand ``~`` in the provided path to the user's home directory (:gh:`10685`, :gh:`10688` by `Richard Höchenberger`_)

- Fix bug in :func:`mne.io.read_raw_eeglab` and :func:`mne.read_epochs_eeglab`, where the presence of channels without position in the ``.set`` file caused positions incorrectly assigned to all further channels (:gh:`8754` by `Mikołaj Magnuski`_)

- Combining channels of :class:`mne.Epochs` or :class:`mne.Evoked` objects now properly retains baseline information (:gh:`10703` by `Clemens Brunner`_)

- In :class:`mne.Report`, some figures would have an undesired border added to the edges; this has now been resolved (:gh:`10730` by `Richard Höchenberger`_)

- Fix selection of EEG channels and selected sphere when plotting bridged electrodes with :func:`mne.viz.plot_bridged_electrodes` (:gh:`10753` by `Mathieu Scheltienne`_)

- Fix broken links in :ref:`tut-fix-meshes` (:gh:`10765` by `Alex Rockhill`_)

- The built-in FieldTrip channel adjacency matrix for ``easycapM1`` had a bug, where the channel ``PO8`` was incorrectly labeled as ``PO6`` This has been resolved by updating the adjacency matrix to the latest version provided by FieldTrip (:gh:`10749` by `Richard Höchenberger`_)

- Add a YouTube video tutorial for editing Freesurfer surfaces in Blender to :ref:`tut-fix-meshes` (:gh:`10778` by `Alex Rockhill`_)

- The default interaction style of :meth:`mne.Evoked.plot_field` has been changed such that if behaves like :func:`~mne.viz.plot_alignment` when trying to rotate the head (:gh:`10788` by `Richard Höchenberger`_)

- Add a video on how to operate the intracranial electrode contact location GUI in :ref:`tut-ieeg-localize` (:gh:`10800` by `Alex Rockhill`_)

- Add a video on how to operate the coregistration GUI in :ref:`tut-source-alignment` (:gh:`10802` by `Alex Rockhill`_)

- Add ``show`` and ``block`` arguments to :func:`mne.gui.coregistration` and ``mne.gui.locate_ieeg`` to pop up the GUIs and halt execution of subsequent code respectively (:gh:`10802` by `Alex Rockhill`_)

- Correctly report the number of available projections when printing measurement info in a Jupyter notebook (:gh:`10471` by `Clemens Brunner`_)

- Fix value set in ``raw.orig_format`` for readers of BrainVision (ASCII format), EGI and Artemis123 files (:gh:`10851` by `Mathieu Scheltienne`_)

- When reading EGI MFF files, channel names are no longer ignored and reference channel information is properly incorporated (:gh:`10898` by `Scott Huberty`_ and `Daniel McCloy`_)

- Fix bug in :func:`mne.time_frequency.psd_array_welch` and related functions/methods where the bias was not accounted for when ``average='median'`` (:gh:`10990` by `Eric Larson`_)

- Fix bug in :class:`mne.decoding.TemporalFilter` where filter parameters were not handled properly (:gh:`10968` by `Eric Larson`_)

- Fix documentation bug in ``ica.plot_sources`` to specify that ``picks`` keyword argument is for picking ICA components to plot (:gh:`10936` by `Adam Li`_)

- Annotations contained in EDF files are correctly read as UTF-8 according to the EDF specification (:gh:`10963` by `Clemens Brunner`_)

- Fix bug where complex-valued topoplots caused an error, convert to amplitude instead (:gh:`10978` by `Alex Rockhill`_)

API and behavior changes
~~~~~~~~~~~~~~~~~~~~~~~~
- When creating BEM surfaces via :func:`mne.bem.make_watershed_bem` and :func:`mne.bem.make_flash_bem`, the ``copy`` parameter now defaults to ``True``. This means that instead of creating symbolic links inside the FreeSurfer subject's ``bem`` folder, we now create "actual" files. This should avoid troubles when sharing files across different operating systems and file systems (:gh:`10531` by `Richard Höchenberger`_)

- The ordering of channels returned by :func:`mne.io.read_raw_nirx` is now ordered by channel name, rather than the order provided by the manufacturer. This enables consistent ordering of channels across different file types (:gh:`10555` by `Robert Luke`_)

- For :func:`mne.viz.plot_topomap`, :func:`mne.viz.plot_evoked_topomap`, :func:`mne.viz.plot_arrowmap`, :func:`mne.viz.plot_ica_components`, :meth:`mne.Covariance.plot_topomap`, :meth:`mne.Evoked.plot_topomap`, :meth:`mne.Evoked.animate_topomap`, :meth:`mne.decoding.CSP.plot_patterns`, :meth:`mne.Projection.plot_topomap` and :meth:`mne.preprocessing.ICA.plot_components` the topomap image interpolation was previously a cubic interpolation but now can be ``'linear'`` and ``'nearest'`` as well. Unless ``image_interp='nearest'`` is passed mne uses a subsequent matplotlib bilinear interpolation to make the interpolated image smoother. Previously, ``'image_interp'`` controlled this second interpolation step and, for the first interpolation, the only option was cubic. To simplify, ``image_interp`` is now responsible for the main interpolation and the subsequent matplotlib image interpolation is bilinear but can be changed afterward using ``im.set_interpolation`` (:gh:`10617` by `Alex Rockhill`_)

- The FLASH BEM surface generation via :func:`mne.bem.make_flash_bem` or the :ref:`mne flash_bem` command has now been clarified in terms of expected inputs. In :func:`mne.bem.convert_flash_mris` the ``convert`` parameter is now deprecated and the ``flash5`` and ``flash30`` now accept list of file names or nibabel images. One breaking change is that now the flash files are looked for as mef05_*.mgz and mef30_*.mgz in mri/flash folder (:gh:`10715` by `Alex Gramfort`_)

- :func:`~mne.viz.plot_compare_evokeds` gets a new parameter ``time_unit`` which can be ``"s"`` or ``"ms"`` (:gh:`10950` by `Daniel McCloy`_)

- The ``to_data_frame`` methods for :meth:`Raw <mne.io.Raw.to_data_frame>`, :meth:`Epochs <mne.Epochs.to_data_frame>`, :meth:`Evoked <mne.Evoked.to_data_frame>`, :meth:`SourceEstimate <mne.SourceEstimate.to_data_frame>`, :meth:`EpochsTFR <mne.time_frequency.EpochsTFR.to_data_frame>`, and :meth:`AverageTFR <mne.time_frequency.AverageTFR.to_data_frame>` all now have default ``time_format=None`` (keep time in seconds) instead of ``time_format='ms'`` (convert time to milliseconds) (:gh:`10925` by `Daniel McCloy`_)

- :func:`mne.Evoked.decimate` now aligns to the sample at time=0 (so that the exact sample when the event occurred is preserved) to be consistent with :func:`mne.Epochs.decimate` (:gh:`10945` by `Alex Rockhill`_)

Authors
~~~~~~~

* Adam Li
* Adeline Fecker+
* Alessandro Tonin+
* Alex Ciok+
* Alex Rockhill
* Alexandre Gramfort
* Archit Singhal+
* Ashley Drew+
* Ben Beasley+
* Carina Forster+
* Christian O'Reilly
* Clemens Brunner
* Cora Kim
* Daniel McCloy
* Dominik Welke
* Dominique Makowski
* Eric Larson
* Evan Hathaway
* Frederik D. Weber+
* Guillaume Favelier
* Hamid Maymandi+
* Ilias Machairas+
* Jean-Remi King
* Johann Benerradi
* Jon Houck
* Jona Sassenhagen
* Jordan Drew+
* Lukas Gemein+
* Marijn van Vliet
* Martin Schulz
* Mathieu Scheltienne
* Matt Courtemanche+
* Matthias Dold+
* Matti Toivonen+
* Michiru Kaneda+
* Mikołaj Magnuski
* Mingjian He+
* Naveen Srinivasan+
* Phillip Alday
* Reza Nasri+
* Reza Shoorangiz
* Richard Höchenberger
* Rob Luke
* Scott Huberty+
* Simon Kern
* Sondre Foslien+
* Stefan Appelhoff
* T. Wang+
* Tziona NessAiver+
